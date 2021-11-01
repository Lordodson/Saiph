// DLL2.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "DLL2.h"


// This is an example of an exported variable
DLL2_API int nDLL2=0;

// This is an example of an exported function.
DLL2_API int fnDLL2(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CDLL2::CDLL2()
{
    return;
}
