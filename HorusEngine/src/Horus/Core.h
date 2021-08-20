#pragma once

#ifdef HOR_PLATFORM_WINDOWS
    #ifdef HOR_BUILD_DLL
        #define HORUS_API __declspec(dllexport)
    #else
        #define HORUS_API __declspec(dllimport)
    #endif // HOR_BUILD_DLL
#else
    #error Horus only supports Windows!!
#endif // HOR_PLATFORM_WINDOWS


#define BIT(x) (1 << x)