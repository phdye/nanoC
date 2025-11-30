# Test Coverage Matrix

Based on Comprehensive Testing Methodology v2.0 (Section 4.2.4)

## Project: nanoC Compiler

---

## Lexer Token Coverage Matrix

| Token Type | Test File | Status |
|------------|-----------|--------|
| IDENTIFIER | test_identifiers.c | Complete |
| ASSIGN | test_assignment.c | Complete |
| LBRA | test_operators_single.c | Complete |
| RBRA | test_operators_single.c | Complete |
| LPAR | test_operators_single.c | Complete |
| RPAR | test_operators_single.c | Complete |
| LSBR | test_operators_single.c | Complete |
| RSBR | test_operators_single.c | Complete |
| SC | test_operators_single.c | Complete |
| COMMA | test_operators_single.c | Complete |
| INT | test_keywords.c | Complete |
| VOID | test_keywords.c | Complete |
| CHAR | test_keywords.c | Complete |
| IF | test_keywords.c | Complete |
| ELSE | test_keywords.c | Complete |
| WHILE | test_keywords.c | Complete |
| RETURN | test_keywords.c | Complete |
| STRUCT | test_keywords.c | Complete |
| SIZEOF | test_keywords.c | Complete |
| CONTINUE | test_keywords.c | Complete |
| BREAK | test_keywords.c | Complete |
| INCLUDE | test_include_*.c | Complete |
| CHAR_LITERAL | test_char_*.c | Complete |
| STRING_LITERAL | test_string_*.c | Complete |
| INT_LITERAL | test_int_literals.c | Complete |
| LOGAND | test_operators_logical.c | Complete |
| LOGOR | test_operators_logical.c | Complete |
| EQ | test_operators_comparison.c | Complete |
| NE | test_operators_comparison.c | Complete |
| LT | test_operators_comparison.c | Complete |
| GT | test_operators_comparison.c | Complete |
| LE | test_operators_comparison.c | Complete |
| GE | test_operators_comparison.c | Complete |
| PLUS | test_operators_single.c | Complete |
| MINUS | test_operators_single.c | Complete |
| NOT | test_operators_logical.c | Complete |
| ASTERISK | test_operators_single.c | Complete |
| DIV | test_operators_single.c | Complete |
| REM | test_operators_single.c | Complete |
| AND | test_operators_logical.c | Complete |
| OR | test_operators_logical.c | Complete |
| DOT | test_operators_single.c | Complete |
| COMMENT | test_comments_*.c | Complete |

**Total Token Types: 44**
**Covered: 44 (100%)**

---

## Parser AST Node Coverage Matrix

| AST Node Type | Test Files | Status |
|---------------|------------|--------|
| Program | All parser tests | Complete |
| FuncDecl | test_empty_main.c, test_func_*.c | Complete |
| FunProto | test_func_prototype.c | Complete |
| VarDecl | test_var_decl_*.c | Complete |
| StructDecl | test_struct_decl.c | Complete |
| Block | test_if_*.c, test_while_*.c | Complete |
| If | test_if_*.c | Complete |
| While | test_while_*.c | Complete |
| Return | test_return_literal.c | Complete |
| Break | test_while_break.c | Complete |
| Continue | test_while_continue.c | Complete |
| Binary | test_binary_*.c | Complete |
| Unary | test_unary_*.c | Complete |
| Primary | test_return_literal.c | Complete |
| Call | test_func_call*.c | Complete |
| Subscript | test_array_subscript.c | Complete |
| Member | test_struct_member_access.c | Complete |
| TypeCast | test_type_cast.c | Complete |
| Type | All tests | Complete |

**Total AST Node Types: 19**
**Covered: 19 (100%)**

---

## Semantic Analysis Error Coverage Matrix

### Name Analysis Errors

| Error Type | Test File | Status |
|------------|-----------|--------|
| Undeclared variable | test_undeclared_variable.c | Complete |
| Undeclared function | test_undeclared_function.c | Complete |
| Undeclared struct | test_undeclared_struct.c | Complete |
| Duplicate variable | test_duplicate_var_same_scope.c | Complete |
| Duplicate function | test_duplicate_function.c | Complete |
| Duplicate struct | test_duplicate_struct.c | Complete |
| Duplicate struct field | test_duplicate_struct_field.c | Complete |
| Duplicate function param | test_duplicate_func_param.c | Complete |
| Proto mismatch (return) | test_func_proto_mismatch_return.c | Complete |
| Proto mismatch (args) | test_func_proto_mismatch_args.c | Complete |

**Total Error Types: 10**
**Covered: 10 (100%)**

### Type Analysis Errors

| Error Type | Test File | Status |
|------------|-----------|--------|
| Invalid binary op (struct) | test_invalid_binary_struct.c | Complete |
| Invalid binary op (pointer) | test_invalid_binary_pointer.c | Complete |
| Invalid return type | test_invalid_return_type.c | Complete |
| Invalid return value | test_invalid_return_value.c | Complete |
| Invalid func call args | test_invalid_func_call_args.c | Complete |
| Invalid func call arg type | test_invalid_func_call_arg_type.c | Complete |
| Invalid if condition | test_invalid_if_condition.c | Complete |
| Invalid while condition | test_invalid_while_condition.c | Complete |
| Non-lvalue assignment | test_non_lvalue_assignment.c | Complete |
| Non-lvalue address | test_non_lvalue_address.c | Complete |
| Deref non-pointer | test_deref_non_pointer.c | Complete |
| Invalid member access | test_invalid_member_access.c | Complete |
| Non-existent field | test_non_existent_field.c | Complete |
| Invalid subscript (non-array) | test_invalid_subscript_non_array.c | Complete |
| Invalid subscript (index) | test_invalid_subscript_index.c | Complete |
| Invalid unary not | test_invalid_unary_not.c | Complete |
| Invalid unary minus | test_invalid_unary_minus.c | Complete |

**Total Error Types: 17**
**Covered: 17 (100%)**

---

## Code Generation Operations Coverage Matrix

| Operation Category | Tests | Status |
|-------------------|-------|--------|
| Addition | test_arithmetic_add.c | Complete |
| Subtraction | test_arithmetic_sub.c | Complete |
| Multiplication | test_arithmetic_mul.c | Complete |
| Division | test_arithmetic_div.c | Complete |
| Modulo | test_arithmetic_mod.c | Complete |
| Negation | test_arithmetic_negative.c, test_unary_negate.c | Complete |
| Less than | test_comparison_lt.c | Complete |
| Greater than | test_comparison_gt.c | Complete |
| Less or equal | test_comparison_le.c | Complete |
| Greater or equal | test_comparison_ge.c | Complete |
| Equal | test_comparison_eq.c | Complete |
| Not equal | test_comparison_ne.c | Complete |
| Logical AND | test_logical_and.c | Complete |
| Logical OR | test_logical_or.c | Complete |
| Logical NOT | test_logical_not.c | Complete |
| If statement | test_if_true.c, test_if_false.c | Complete |
| If-else | test_if_else_true.c, test_if_else_false.c | Complete |
| While loop | test_while_loop.c | Complete |
| Break | test_while_break.c | Complete |
| Continue | test_while_continue.c | Complete |
| Function call | test_function_call.c | Complete |
| Function args | test_function_args.c | Complete |
| Recursion | test_recursion_*.c | Complete |
| Pointer deref | test_pointer_basic.c | Complete |
| Pointer modify | test_pointer_modify.c | Complete |
| Array access | test_array_basic.c | Complete |
| Array iteration | test_array_sum.c | Complete |
| Struct access | test_struct_basic.c | Complete |
| Nested struct | test_struct_nested.c | Complete |
| Char literal | test_char_literal.c | Complete |
| Char escape | test_char_escape.c | Complete |
| Type cast | test_type_cast.c | Complete |
| Complex expression | test_complex_expr.c | Complete |
| Nested loops | test_nested_loops.c | Complete |

**Total Operations: 34**
**Covered: 34 (100%)**

---

## Test Count Summary

| Category | Test Count |
|----------|------------|
| Lexer | 17 |
| Parser | 30 |
| Name Analysis | 12 |
| Type Analysis | 20 |
| Code Generation | 38 |
| Integration | 7 |
| Edge Cases | 12 |
| Error Recovery | 8 |
| Benchmarks | 5 |

**Total Tests: 149**

---

## Coverage Summary

| Component | Coverage Target | Status |
|-----------|-----------------|--------|
| Lexer Token Types | 100% | Complete |
| Parser Grammar Rules | 100% | Complete |
| Name Analysis Errors | 100% | Complete |
| Type Analysis Errors | 100% | Complete |
| Code Gen Operations | 100% | Complete |
| Error Paths | 100% | Complete |
