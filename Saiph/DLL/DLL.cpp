// DLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "DLL.h"


// This is an example of an exported variable
DLL_API int nDLL=0;

// This is an example of an exported function.
DLL_API int fnDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CDLL::CDLL()
{
    return;
}
