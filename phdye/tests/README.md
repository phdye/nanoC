# Comprehensive Test Suite for nanoC Compiler

Based on the Comprehensive Testing Methodology v2.0

## Project Feature Detection

This project is a **Parser/Compiler**, which activates the following requirements:
- Parser-Specific Testing (Section 6.1.5)
- Grammar Coverage
- Error Recovery Testing

## Test Organization

```
phdye/tests/
├── lexer/              # Lexer unit tests - all token types
├── parser/             # Parser unit tests - all AST nodes
├── name_analysis/      # Name analysis tests - symbol resolution
├── type_analysis/      # Type analysis tests - type checking
├── code_gen/           # Code generation tests - execution verification
├── integration/        # End-to-end integration tests
├── edge_cases/         # Boundary condition tests
├── error_recovery/     # Error handling and recovery tests
├── benchmarks/         # Performance benchmarks
└── run_tests.sh        # Test runner script
```

## Coverage Targets

| Component | Target | Current |
|-----------|--------|---------|
| Lexer - Token Types | 100% | TBD |
| Parser - Grammar Rules | 100% | TBD |
| Name Analysis - Scope Rules | 100% | TBD |
| Type Analysis - Type Rules | 100% | TBD |
| Code Generation - Operations | 100% | TBD |
| Error Paths | 100% | TBD |

## Test Categories

### 1. Lexer Tests
- All 44 token types tested individually
- Multi-character operators (==, !=, <=, >=, &&, ||)
- String and character literals with escape sequences
- Comments (single-line and multi-line)
- Include directives
- Error conditions (unclosed strings, unclosed chars)

### 2. Parser Tests
- All expression types (Primary, Unary, Binary, Call, etc.)
- All statement types (If, While, Return, Break, Continue)
- All declaration types (VarDecl, FuncDecl, StructDecl)
- Operator precedence
- Error recovery from syntax errors

### 3. Name Analysis Tests
- Variable declaration and scope
- Function declaration and prototypes
- Struct declaration and field access
- Duplicate declaration detection
- Undeclared identifier detection
- Scope nesting

### 4. Type Analysis Tests
- Type compatibility in assignments
- Type compatibility in operations
- Function call argument types
- Return type checking
- Pointer and array type handling
- Type casting

### 5. Code Generation Tests
- Arithmetic operations
- Comparison operations
- Logical operations
- Control flow (if/else, while, break, continue)
- Function calls and recursion
- Pointer operations
- Struct member access
- Array subscript operations

### 6. Integration Tests
- Complete programs with multiple features
- Standard library usage
- Complex expressions
- Nested control structures

### 7. Edge Case Tests
- Empty inputs
- Maximum/minimum values
- Deeply nested structures
- Very long identifiers
- Unicode in strings

### 8. Error Recovery Tests
- Missing semicolons
- Missing braces
- Missing parentheses
- Invalid operators
- Invalid type combinations

## Running Tests

```bash
cd phdye/tests
./run_tests.sh
```

## Test File Format

Each test file contains an expected output comment at the top:
```c
/*
Expected output here
*/
// Test code below
```

## Bottom-Up Testing Order

Following the Comprehensive Testing Methodology:
1. Level 1: Lexer (no internal dependencies)
2. Level 2: Parser (depends on Lexer)
3. Level 3: Name Analysis (depends on Parser)
4. Level 4: Type Analysis (depends on Name Analysis)
5. Level 5: IR Generation (depends on Type Analysis)
6. Level 6: Code Generation (depends on IR)
