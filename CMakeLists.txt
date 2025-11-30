cmake_minimum_required(VERSION 3.28)
project(compiler)

set(CMAKE_CXX_STANDARD 17)

# Platform detection and configuration
if(APPLE)
    message(STATUS "Configuring for macOS")
    set(PLATFORM_NAME "macos")
    add_compile_definitions(PLATFORM_MACOS=1)
    add_compile_definitions(PLATFORM_LINUX=0)
elseif(UNIX)
    message(STATUS "Configuring for Linux/Cygwin")
    set(PLATFORM_NAME "linux")
    add_compile_definitions(PLATFORM_MACOS=0)
    add_compile_definitions(PLATFORM_LINUX=1)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()


# Copy platform-specific print.c at configure time
configure_file(
    ${CMAKE_SOURCE_DIR}/std/print_${PLATFORM_NAME}.c
    ${CMAKE_SOURCE_DIR}/std/print.c
    COPYONLY
)


add_executable(compiler main.cpp
        lexer/lexer.cpp
        lexer/token.cpp
        parser/parser.cpp
        parser/decl.cpp
        parser/stmt.cpp
        parser/expr.cpp
        semantic/name_analysis.cpp
        parser/ast.cc
        semantic/type_analysis.cpp
        ir/cfg_gen.cpp
        ir/ir.h
        x86/code_gen.cpp
        ir/instruction_gen.cpp
        ir/ir_printer.h
        ir/reg_alloc.cpp
)
