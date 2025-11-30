# nanoC Code Review

**Reviewed:** 2025-11-30
**Reviewer:** Claude Code
**Project:** nanoC - Educational C Compiler
**Codebase Size:** ~3,800 lines across 30 files

---

## Executive Summary

nanoC is a well-structured educational C compiler that demonstrates a clear understanding of compiler architecture. The codebase follows a classic 5-stage pipeline (lexing, parsing, semantic analysis, IR generation, code generation) with good separation of concerns. However, there are several areas for improvement in code quality, security, and adherence to modern C++ best practices.

**Overall Assessment:** Good educational project with room for improvement in production-readiness.

| Category | Rating | Notes |
|----------|--------|-------|
| Code Quality | 6/10 | Functional but inconsistent styling and some code smells |
| Security | 5/10 | Path traversal vulnerability and missing input validation |
| Best Practices | 5/10 | Several C++ best practices not followed |
| Architecture | 8/10 | Clean separation, good use of Visitor pattern |
| Documentation | 6/10 | Good README, lacking inline documentation |

---

## Table of Contents

1. [Security Vulnerabilities](#1-security-vulnerabilities)
2. [Code Quality Issues](#2-code-quality-issues)
3. [C++ Best Practices](#3-c-best-practices)
4. [Architecture Review](#4-architecture-review)
5. [Recommendations](#5-recommendations)

---

## 1. Security Vulnerabilities

### 1.1 Critical: Path Traversal in Include Directive

**File:** `parser/parser.cpp:27-28`
**Severity:** High

```cpp
std::string f = consume(TT::INCLUDE, "Expected #include directive")->value;
std::string path = "../std/" + f + ".c";
```

**Issue:** User-controlled input is directly concatenated into a file path without any sanitization. An attacker could craft a malicious include directive to read arbitrary files:

```c
#include <../../etc/passwd>
#include <../../../sensitive/data>
```

**Recommendation:**
- Validate that the include path contains no path separators (`/`, `\`, `..`)
- Use a whitelist of allowed include files
- Resolve to canonical path and verify it's within allowed directory

```cpp
// Suggested fix
std::string f = consume(TT::INCLUDE, "Expected #include directive")->value;
if (f.find('/') != std::string::npos || f.find('\\') != std::string::npos ||
    f.find("..") != std::string::npos) {
    throw parsing_exception("Invalid characters in include path", peek(0));
}
```

### 1.2 Medium: Unvalidated String Literals in Assembly Output

**File:** `ir/instruction_gen.cpp:113`

```cpp
emit("emit_asm", Register::get_physical_register("rax"),
     std::dynamic_pointer_cast<Primary>(c->args[0])->token->value);
```

**Issue:** String literals from source code are emitted directly into assembly without escaping. While the current `emit_asm` function is internal, malformed strings could potentially cause assembly syntax errors or unexpected behavior.

**Recommendation:** Validate or sanitize assembly string content before emission.

### 1.3 Low: Integer Overflow in Stack Allocation

**File:** `ir/reg_alloc.cpp:26-32`

```cpp
offset += 8;
// ...
offset += std::stoi(std::dynamic_pointer_cast<BasicInstruction>(inst)->value);
```

**Issue:** Stack offset calculations have no bounds checking. Extremely large allocations could cause integer overflow.

**Recommendation:** Add bounds checking for maximum stack frame size.

### 1.4 Low: Missing Error Handling for File Operations

**File:** `parser/parser.cpp:46-47`

```cpp
catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
return program->decls;  // Potentially using invalid program
```

**Issue:** After catching an exception during include parsing, the code continues to use `program->decls` which may be in an undefined state.

---

## 2. Code Quality Issues

### 2.1 Inconsistent File Extensions

**Files:** `parser/ast.cc` vs `parser/decl.cpp`

The project mixes `.cc` and `.cpp` extensions for C++ source files. This creates inconsistency.

**Recommendation:** Standardize on one extension (`.cpp` is more common).

### 2.2 Global Mutable State

**File:** `ir/instruction_gen.cpp:7`

```cpp
int VirtualRegister::count = 0;
```

**Issue:** Static mutable state makes the code non-reentrant and harder to test. Running the compiler twice in the same process would have register naming conflicts.

**Recommendation:** Move counter into a context object or reset between compilations.

### 2.3 Large Monolithic Header File

**File:** `parser/ast.h` (488 lines)

**Issue:** All AST node definitions are in a single header file, increasing compilation time and coupling.

**Recommendation:** Consider splitting into multiple headers:
- `ast_base.h` - Base classes and Visitor
- `ast_expr.h` - Expression nodes
- `ast_stmt.h` - Statement nodes
- `ast_decl.h` - Declaration nodes

### 2.4 Variable Shadowing in Nested Loops

**File:** `ir/reg_alloc.cpp:51`

```cpp
for (int i=0;i<instructions.size();i++) {
    // ...
    for (int i=0;i<inst->registers.size();i++){  // Shadows outer 'i'
```

**Issue:** Inner loop variable `i` shadows outer loop variable, creating potential for bugs.

**Recommendation:** Use distinct variable names (`j`, `regIdx`, etc.).

### 2.5 Magic Numbers

**Multiple files**

Examples:
- `ir/instruction_gen.cpp:49`: `static_cast<size_t>(6)` - number of register arguments
- `ir/reg_alloc.cpp:26`: `offset += 8` - size of stack slot
- `semantic/name_analysis.cpp:229-236`: Type sizes

**Recommendation:** Define named constants:

```cpp
constexpr size_t MAX_REGISTER_ARGS = 6;
constexpr int STACK_SLOT_SIZE = 8;
constexpr int INT_SIZE = 8;
constexpr int CHAR_SIZE = 8;
```

### 2.6 Empty Function Bodies Without Explanation

**File:** `semantic/name_analysis.cpp:250-253`

```cpp
void NameAnalysis::visit(std::shared_ptr<Continue> c) {
}

void NameAnalysis::visit(std::shared_ptr<Break> b) {
}
```

**Recommendation:** Add comments explaining why these are intentionally empty, or consider using a default implementation in the base class.

### 2.7 Operator Precedence Ambiguity

**File:** `parser/expr.cpp:61`

```cpp
if (accept({TT::MINUS, TT::ASTERISK, TT::AND, TT::NOT}) || accept(TT::LPAR) && accept({TT::STRUCT,TT::INT,TT::CHAR,TT::VOID},1)){
```

**Issue:** Mix of `||` and `&&` without explicit parentheses makes precedence unclear.

**Recommendation:** Add explicit parentheses for clarity.

### 2.8 Inconsistent Formatting

**Multiple files**

The codebase has inconsistent:
- Brace placement (same line vs new line)
- Spacing around operators
- Blank lines between functions

**Recommendation:** Apply a consistent code formatter (clang-format) with a `.clang-format` config file.

---

## 3. C++ Best Practices

### 3.1 Missing `override` Keyword

**File:** `parser/ast.h` (multiple locations)

```cpp
void accept(Visitor<void>& visitor){  // Missing override
    visitor.visit(shared_from_this());
}
```

**Recommendation:** Add `override` to all virtual method implementations for compile-time checking.

### 3.2 Missing `const` Correctness

**Multiple files**

Examples:
- `lexer/lexer.cpp:260-268`: `reachedEnd()` and `peek()` should be `const`
- Many visitor methods could take `const` shared_ptr references

```cpp
// Current
char Lexer::peek();
// Better
char Lexer::peek() const;
```

### 3.3 Pass-by-Value Instead of Const Reference

**File:** `semantic/name_analysis.cpp:7, 16, 23`

```cpp
std::shared_ptr<Symbol> NameAnalysis::get(std::string identifier) {
```

**Recommendation:** Pass `std::string` by const reference to avoid copies:

```cpp
std::shared_ptr<Symbol> NameAnalysis::get(const std::string& identifier);
```

### 3.4 Excessive Use of `shared_ptr`

**Multiple files**

The codebase uses `std::shared_ptr` almost universally, even where:
- `std::unique_ptr` would suffice (single ownership)
- Raw pointers or references would work (non-owning)

**Recommendation:** Use `unique_ptr` for single ownership, raw pointers/references for non-owning access.

### 3.5 Missing Standard Header Includes

**File:** `main.cpp`

```cpp
// Uses strcmp without including <cstring>
if (argc > 2 && strcmp(argv[2],"-lexer") == 0){
```

**Recommendation:** Add explicit includes rather than relying on transitive includes:

```cpp
#include <cstring>  // for strcmp
```

### 3.6 Global Type Alias

**File:** `lexer/token.h:19`

```cpp
using TT = TokenType;
```

**Issue:** Global namespace pollution; could conflict with other code.

**Recommendation:** Keep alias local to implementation files or use full name.

### 3.7 Public Member Variables

**File:** `parser/ast.h` (throughout)

All AST node members are public. While acceptable for data structures, this exposes internal representation.

**Recommendation:** For an educational project this is acceptable, but consider getters for more complex scenarios.

### 3.8 Exception Classes Not Deriving from `std::runtime_error`

**Files:** `lexer/lexing_exception.h`, `parser/parsing_exception.h`, `semantic/semantic_exception.h`

```cpp
class lexing_exception : public std::exception {
```

**Recommendation:** Derive from `std::runtime_error` for standard message handling:

```cpp
class lexing_exception : public std::runtime_error {
public:
    lexing_exception(const std::string& msg, int line, int col)
        : std::runtime_error(format_message(msg, line, col)) {}
};
```

### 3.9 Use of `nullptr` vs `NO_REGISTER`

**File:** `ir/instruction_gen.h:16`

```cpp
std::shared_ptr<VirtualRegister> NO_REGISTER = nullptr;
```

**Issue:** Using a named `nullptr` is good, but it's a member variable that could be accidentally modified.

**Recommendation:** Make it `static constexpr` or use `std::nullopt` with `std::optional`.

### 3.10 Missing `noexcept` Specifications

**Multiple files**

Functions that don't throw should be marked `noexcept` for optimization and documentation:

```cpp
bool Lexer::reachedEnd() noexcept;
char Lexer::peek() noexcept;
```

---

## 4. Architecture Review

### 4.1 Strengths

1. **Clean Pipeline Architecture:** Each compilation stage is clearly separated with well-defined interfaces.

2. **Visitor Pattern:** Good use of the Visitor pattern for AST traversal, enabling easy addition of new passes.

3. **Consistent Error Handling:** Custom exception classes for each phase provide clear error categorization.

4. **Comprehensive Test Suite:** 67 test files covering all compiler phases.

5. **Symbol Table Design:** Stack-based scope management is clean and correct.

### 4.2 Areas for Improvement

1. **IR Design:** The IR is close to x86 assembly. A more abstract IR would enable:
   - Target-independent optimizations
   - Easier retargeting to other architectures
   - SSA form for better optimization potential

2. **Register Allocation:** The naive spill-everywhere approach works but is inefficient. Consider:
   - Linear scan register allocation
   - Graph coloring

3. **Error Recovery:** The compiler stops at the first error. Implementing error recovery would improve user experience.

4. **String Handling:** String literals are stored in the token value but there's no proper data section generation.

---

## 5. Recommendations

### High Priority

1. **Fix Path Traversal Vulnerability** - Security critical
2. **Add Input Validation** - Prevent potential injection attacks
3. **Reset Static Counters** - Fix reentrancy issues
4. **Apply Code Formatter** - Improve consistency

### Medium Priority

5. **Add `const` Correctness** - Better documentation and optimization
6. **Use `override` Keyword** - Catch bugs at compile time
7. **Replace Magic Numbers** - Improve maintainability
8. **Add Missing Includes** - Ensure portability

### Low Priority (Enhancements)

9. **Split Large Header Files** - Improve compilation time
10. **Add Documentation Comments** - Help future contributors
11. **Consider `unique_ptr`** - Reduce reference counting overhead
12. **Implement Error Recovery** - Better user experience

---

## Appendix: File-by-File Summary

| File | Lines | Issues |
|------|-------|--------|
| `main.cpp` | 113 | Missing include, could use better arg parsing |
| `lexer/lexer.cpp` | 280 | Missing const, good structure |
| `lexer/token.h` | 41 | Global type alias |
| `parser/ast.h` | 488 | Large file, missing override |
| `parser/parser.cpp` | 108 | **Path traversal vulnerability** |
| `parser/expr.cpp` | 186 | Operator precedence ambiguity |
| `semantic/name_analysis.cpp` | 254 | Pass by value, empty functions |
| `semantic/type_analysis.cpp` | 239 | Good type checking logic |
| `ir/instruction_gen.cpp` | 500 | Magic numbers, global state |
| `ir/reg_alloc.cpp` | 92 | Variable shadowing |
| `x86/code_gen.cpp` | 115 | Clean code generation |

---

## Conclusion

nanoC is a solid educational compiler that successfully demonstrates the fundamentals of compiler construction. The security vulnerabilities should be addressed if the compiler will be used with untrusted input. The code quality and best practices issues are typical of a project focused on learning rather than production use.

For educational purposes, the codebase serves its goal well. For production use, the recommendations above should be implemented, particularly the security fixes and improved error handling.
