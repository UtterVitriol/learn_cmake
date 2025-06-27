#pragma once
#include <Windows.h>

typedef int(*tMessageBoxA)(HWND, LPCSTR, LPCSTR, ULONG);
int init_hooks();
