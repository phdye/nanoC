//
// Platform-specific definitions for nanoC compiler
//

#ifndef COMPILER_PLATFORM_H
#define COMPILER_PLATFORM_H

// Platform detection - now set by CMakeLists.txt
// PLATFORM_MACOS and PLATFORM_LINUX are defined via add_compile_definitions

#if PLATFORM_MACOS
    // macOS syscalls (BSD-style with 0x2000000 offset)
    #define SYSCALL_EXIT "0x2000001"
    #define SYSCALL_WRITE "0x2000004"
    #define ENTRY_POINT "start"
#elif PLATFORM_LINUX
    // Linux/Cygwin syscalls
    #define SYSCALL_EXIT "60"
    #define SYSCALL_WRITE "1"
    #define ENTRY_POINT "_start"
#else
    #error "Platform not defined - check CMakeLists.txt"
#endif

#endif // COMPILER_PLATFORM_H
