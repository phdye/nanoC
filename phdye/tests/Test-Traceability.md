# Test-to-Requirement Traceability Matrix

Based on Comprehensive Testing Methodology v2.0 (Section 4.2.3)

## Project: nanoC Compiler

### Feature: Parser/Compiler

This project activates Parser-Specific Testing requirements (Section 6.1.5).

---

## Module: Lexer

### Requirement L1: Tokenize all C keywords
- Tested by: `lexer/test_keywords.c`
- Coverage: 100% (11 keywords)
- Status: Complete

### Requirement L2: Tokenize all single-character operators
- Tested by: `lexer/test_operators_single.c`
- Coverage: 100% (14 operators)
- Status: Complete

### Requirement L3: Tokenize all comparison operators
- Tested by: `lexer/test_operators_comparison.c`
- Coverage: 100% (6 operators)
- Status: Complete

### Requirement L4: Tokenize logical and bitwise operators
- Tested by: `lexer/test_operators_logical.c`
- Coverage: 100% (5 operators)
- Status: Complete

### Requirement L5: Tokenize identifiers
- Tested by: `lexer/test_identifiers.c`
- Coverage: Multiple patterns tested
- Status: Complete

### Requirement L6: Tokenize integer literals
- Tested by: `lexer/test_int_literals.c`
- Coverage: Including edge cases (0, max int)
- Status: Complete

### Requirement L7: Tokenize character literals with escape sequences
- Tested by: `lexer/test_char_literals.c`, `lexer/test_char_escape_sequences.c`
- Coverage: All 7 escape sequences
- Status: Complete

### Requirement L8: Tokenize string literals with escape sequences
- Tested by: `lexer/test_string_literals.c`, `lexer/test_string_escape_sequences.c`
- Coverage: All escape sequences
- Status: Complete

### Requirement L9: Handle comments
- Tested by: `lexer/test_comments_single_line.c`, `lexer/test_comments_multi_line.c`
- Coverage: Single-line and multi-line comments
- Status: Complete

### Requirement L10: Handle include directives
- Tested by: `lexer/test_include_angle.c`, `lexer/test_include_quote.c`
- Coverage: Both <> and "" formats
- Status: Complete

---

## Module: Parser

### Requirement P1: Parse function declarations
- Tested by: `parser/test_empty_main.c`, `parser/test_func_with_args.c`, `parser/test_void_function.c`
- Coverage: void/int return, with/without args
- Status: Complete

### Requirement P2: Parse function prototypes
- Tested by: `parser/test_func_prototype.c`
- Coverage: Forward declarations
- Status: Complete

### Requirement P3: Parse variable declarations
- Tested by: `parser/test_var_decl_int.c`, `parser/test_var_decl_char.c`, `parser/test_var_decl_pointer.c`, `parser/test_var_decl_array.c`
- Coverage: int, char, pointers, arrays
- Status: Complete

### Requirement P4: Parse struct declarations
- Tested by: `parser/test_struct_decl.c`, `parser/test_struct_member_access.c`
- Coverage: Definition and member access
- Status: Complete

### Requirement P5: Parse all expression types
- Tested by: `parser/test_binary_*.c`, `parser/test_unary_*.c`, `parser/test_complex_expression.c`
- Coverage: Binary, unary, type cast, sizeof, function calls
- Status: Complete

### Requirement P6: Parse control flow statements
- Tested by: `parser/test_if_*.c`, `parser/test_while_*.c`
- Coverage: if, if-else, nested if, while, break, continue
- Status: Complete

### Requirement P7: Handle operator precedence
- Tested by: `parser/test_binary_arithmetic.c`, `parser/test_complex_expression.c`
- Coverage: Arithmetic, comparison, logical precedence
- Status: Complete

---

## Module: Name Analysis

### Requirement N1: Detect undeclared variables
- Tested by: `name_analysis/test_undeclared_variable.c`
- Status: Complete

### Requirement N2: Detect undeclared functions
- Tested by: `name_analysis/test_undeclared_function.c`
- Status: Complete

### Requirement N3: Detect undeclared structs
- Tested by: `name_analysis/test_undeclared_struct.c`
- Status: Complete

### Requirement N4: Detect duplicate declarations
- Tested by: `name_analysis/test_duplicate_*.c`
- Coverage: Variables, functions, structs, struct fields, parameters
- Status: Complete

### Requirement N5: Handle scope correctly
- Tested by: `name_analysis/test_scope_shadowing_valid.c`
- Status: Complete

### Requirement N6: Validate function prototypes
- Tested by: `name_analysis/test_func_proto_mismatch_*.c`, `name_analysis/test_valid_forward_decl.c`
- Status: Complete

---

## Module: Type Analysis

### Requirement T1: Validate binary operator types
- Tested by: `type_analysis/test_invalid_binary_*.c`
- Status: Complete

### Requirement T2: Validate return types
- Tested by: `type_analysis/test_invalid_return_*.c`
- Status: Complete

### Requirement T3: Validate function call arguments
- Tested by: `type_analysis/test_invalid_func_call_*.c`
- Status: Complete

### Requirement T4: Validate condition expressions
- Tested by: `type_analysis/test_invalid_if_condition.c`, `type_analysis/test_invalid_while_condition.c`
- Status: Complete

### Requirement T5: Validate lvalue operations
- Tested by: `type_analysis/test_non_lvalue_*.c`
- Status: Complete

### Requirement T6: Validate pointer operations
- Tested by: `type_analysis/test_deref_non_pointer.c`, `type_analysis/test_valid_pointer_ops.c`
- Status: Complete

### Requirement T7: Validate member access
- Tested by: `type_analysis/test_invalid_member_access.c`, `type_analysis/test_non_existent_field.c`
- Status: Complete

### Requirement T8: Validate subscript operations
- Tested by: `type_analysis/test_invalid_subscript_*.c`, `type_analysis/test_valid_array_ops.c`
- Status: Complete

### Requirement T9: Validate unary operations
- Tested by: `type_analysis/test_invalid_unary_*.c`
- Status: Complete

---

## Module: Code Generation

### Requirement C1: Generate correct arithmetic operations
- Tested by: `code_gen/test_arithmetic_*.c`
- Coverage: add, sub, mul, div, mod, negative
- Status: Complete

### Requirement C2: Generate correct comparison operations
- Tested by: `code_gen/test_comparison_*.c`
- Coverage: <, >, <=, >=, ==, !=
- Status: Complete

### Requirement C3: Generate correct logical operations
- Tested by: `code_gen/test_logical_*.c`
- Coverage: &&, ||, !
- Status: Complete

### Requirement C4: Generate correct control flow
- Tested by: `code_gen/test_if_*.c`, `code_gen/test_while_*.c`
- Coverage: if, if-else, while, break, continue
- Status: Complete

### Requirement C5: Generate correct function calls
- Tested by: `code_gen/test_function_*.c`, `code_gen/test_recursion_*.c`
- Coverage: Simple calls, with arguments, recursion
- Status: Complete

### Requirement C6: Generate correct pointer operations
- Tested by: `code_gen/test_pointer_*.c`
- Coverage: Address-of, dereference, modification
- Status: Complete

### Requirement C7: Generate correct array operations
- Tested by: `code_gen/test_array_*.c`
- Coverage: Indexing, iteration
- Status: Complete

### Requirement C8: Generate correct struct operations
- Tested by: `code_gen/test_struct_*.c`
- Coverage: Member access, nested structs
- Status: Complete

---

## Integration Tests

### End-to-end program execution
- Tested by: `integration/test_bubble_sort.c`
- Tested by: `integration/test_binary_search.c`
- Tested by: `integration/test_gcd.c`
- Tested by: `integration/test_prime_check.c`
- Tested by: `integration/test_linked_list_simulation.c`
- Tested by: `integration/test_multiple_functions.c`
- Tested by: `integration/test_power_function.c`
- Status: Complete

---

## Edge Case Tests

### Boundary conditions
- Tested by: `edge_cases/test_*.c`
- Coverage: Empty functions, zero values, max int, negative numbers, deep nesting, long identifiers
- Status: Complete

---

## Error Recovery Tests

### Error detection and reporting
- Tested by: `error_recovery/test_*.c`
- Coverage: Missing semicolons, braces, parens, unclosed literals, invalid includes
- Status: Complete
