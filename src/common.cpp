#include "common.hpp"
#include <Windows.h>
#include <cstdio>
#include "../minhook/include/MinHook.h"

tMessageBoxA oMessageBoxA = NULL;

int hMessageBoxA(HWND hWnd, LPCSTR text, LPCSTR caption, ULONG uType)
{
    printf("%s: %s\n", text, caption);
    return oMessageBoxA(hWnd, "Go fuck yourself", "REE", uType);
}

int
init_hooks ()
{
    int status = 0;

    if (MH_OK
        != (status
            = MH_CreateHook(MessageBoxA, hMessageBoxA, (LPVOID *)&oMessageBoxA)))
    {
        return status;
    }

    if(MH_OK != (status = MH_EnableHook(MH_ALL_HOOKS)))
    {
        return status;
    }

    printf("Status: %d\n", status);

    return status;
}
