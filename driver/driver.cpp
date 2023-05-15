#include "driver.h"

bool Driver::Init()
{
	LoadLibraryA("user32.dll");
	LoadLibraryA("win32u.dll");
	LoadLibraryA(("ntdll.dll"));

	*(PVOID*)&NtUserCreateDesktopEx = GetProcAddress(
		GetModuleHandleA("win32u.dll"),
		("NtUserCreateDesktopEx")
	);

	return true;
}

bool Driver::callbackExample(ULONG64* param1, ULONG64* param2, ULONG64 allocationPtr, ULONG64 allocationSize, ULONG64 mdlptr) {
	UNREFERENCED_PARAMETER(param1);
	UNREFERENCED_PARAMETER(param2);
	UNREFERENCED_PARAMETER(allocationPtr);
	UNREFERENCED_PARAMETER(allocationSize);
	UNREFERENCED_PARAMETER(mdlptr);
	return true;
}


uintptr_t Driver::getbase()
{
	uintptr_t Buffer{};

	_data r{};
	r.code = 123;
	r.buff = (uintptr_t)&Buffer;
	r.base = TRUE;
	r.src = process_id;
	r.dest = GetCurrentProcessId();
	NtUserCreateDesktopEx(NULL, NULL, &r, NULL, NULL, NULL);

	base = Buffer;

	return Buffer;
}

INT32 Driver::find_process(LPCTSTR process_name)
{
	PROCESSENTRY32 pt;
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pt.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hsnap, &pt)) {
		do {
			if (!lstrcmpi(pt.szExeFile, process_name)) {
				CloseHandle(hsnap);
				process_id = pt.th32ProcessID;
				return pt.th32ProcessID;
			}
		} while (Process32Next(hsnap, &pt));
	}
	CloseHandle(hsnap);

	return { NULL };
}
