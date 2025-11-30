# Standard Library Platform Support

## Platform-Specific Files

The nanoC standard library includes platform-specific implementations:

- **print_macos.c** - macOS implementation (uses BSD syscalls: 0x2000004 for write, 0x2000001 for exit)
- **print_linux.c** - Linux/Cygwin implementation (uses Linux syscalls: 1 for write, 60 for exit)

## Build-Time Selection

The CMakeLists.txt automatically copies the correct platform file to `print.c` during configuration:
- On macOS: `print_macos.c` → `print.c`
- On Linux/Cygwin: `print_linux.c` → `print.c`

**Note:** `print.c` is generated and should not be committed to git.

## Adding New Standard Library Functions

If you add new functions that require platform-specific code:
1. Create separate implementations in `function_macos.c` and `function_linux.c`
2. Update CMakeLists.txt to copy the appropriate version
3. Add the generated `function.c` to `.gitignore`
