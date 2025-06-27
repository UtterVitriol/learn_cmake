#include <Windows.h>
#include "common.hpp"
#include "../minhook/include/MinHook.h"

int
main ()
{
    if(MH_OK != MH_Initialize())
    {
        goto END;
    }

    if(MH_OK != init_hooks())
    {
        goto END;
    }

    MessageBoxA(0, "Have a good day", "Good Morning", 0);

END:
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    return 0;
}
