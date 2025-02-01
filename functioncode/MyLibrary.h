#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#ifdef _WIN32
    // Nếu đang dùng Windows với MSVC
    #ifdef MYLIBRARY_EXPORTS
        #define MYLIBRARY_API __declspec(dllexport)
    #else
        #define MYLIBRARY_API __declspec(dllimport)
    #endif
#else
    // Nếu đang dùng GCC hoặc Clang (Linux/macOS)
    #define MYLIBRARY_API __attribute__((visibility("default")))
#endif

extern "C" {
    MYLIBRARY_API int add(int a, int b);
}

#endif
