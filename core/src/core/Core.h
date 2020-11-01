#pragma once

#if defined(_MSC_VER)
    //  Microsoft 
    #define AF_EXPORT __declspec(dllexport)
    #define AF_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define AF_EXPORT __attribute__((visibility("default")))
    #define AF_IMPORT
#else
    //  do nothing and hope for the best?
    #define AF_EXPORT
    #define AF_IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef ANT_FARM_BUILD_CORE
    #define ANT_FARM_PUBLIC AF_EXPORT
#else
    #define ANT_FARM_PUBLIC AF_IMPORT
#endif