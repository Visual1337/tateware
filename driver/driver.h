#pragma once


#include "driverdefs.h"


inline PVOID(__fastcall* NtUserCreateDesktopEx)(PVOID a1, PVOID a2, PVOID a3, PVOID a4, PVOID a5, PVOID a6);

struct _data {
	INT code;

	uintptr_t addr;
	uintptr_t buff;
	SIZE_T size;

	uintptr_t src;
	uintptr_t dest;

	BOOLEAN base;
};

inline INT32 process_id;
inline uintptr_t base;
inline NTSTATUS driver_exit_code = 0;

class Driver {
public:
	static INT32 find_process(LPCTSTR process_name);
	static uintptr_t getbase();
	static bool Init();
	static bool Load();
	static bool callbackExample(ULONG64* param1, ULONG64* param2, ULONG64 allocationPtr, ULONG64 allocationSize, ULONG64 mdlptr);
};

template<typename T>
T rread(uintptr_t Addres, SIZE_T Size = sizeof(T))
{
	T Buffer{};

	_data r{};
	r.code = 123;
	r.addr = Addres;
	r.buff = (uintptr_t)&Buffer;
	r.size = Size;
	r.base = FALSE;
	r.src = process_id;
	r.dest = GetCurrentProcessId();

	NtUserCreateDesktopEx(NULL, NULL, &r, NULL, NULL, NULL);

	return Buffer;
}
