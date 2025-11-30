/*
Program (
    FuncDecl print_c(VarDecl(char)) (void) (
        Func Call emit_asm (sub rsp, 8 )
        Func Call emit_asm (mov [rsp], dil )
        Func Call emit_asm (mov rsi, rsp )
        Func Call emit_asm (mov rdi, 1 )
        Func Call emit_asm (mov rdx, 1 )
        Func Call emit_asm (mov rax, 0x2000004 )
        Func Call emit_asm (syscall )
        Func Call emit_asm (add rsp, 8 )
    )
    FuncDecl print_i(VarDecl(int)) (void) (
        Func Call emit_asm (sub rsp, 20 )
        Func Call emit_asm (mov rax, rdi )
        Func Call emit_asm (mov rcx, 10 )
        Func Call emit_asm (mov byte [rsp], 0 )
        Func Call emit_asm (test rax, rax )
        Func Call emit_asm (jge .not_neg )
        Func Call emit_asm (neg rax )
        Func Call emit_asm (mov byte [rsp], 1 )
        Func Call emit_asm (.not_neg: )
        Func Call emit_asm (lea rdi, [rsp+19] )
        Func Call emit_asm (.convert: )
        Func Call emit_asm (xor rdx, rdx )
        Func Call emit_asm (div rcx )
        Func Call emit_asm (add dl, '0' )
        Func Call emit_asm (dec rdi )
        Func Call emit_asm (mov [rdi], dl )
        Func Call emit_asm (test rax, rax )
        Func Call emit_asm (jnz .convert )
        Func Call emit_asm (cmp byte [rsp], 0 )
        Func Call emit_asm (je .done_sign )
        Func Call emit_asm (dec rdi )
        Func Call emit_asm (mov byte [rdi], '-' )
        Func Call emit_asm (.done_sign: )
        Func Call emit_asm (mov rax, 0x2000004 )
        Func Call emit_asm (mov rsi, rdi )
        Func Call emit_asm (lea rdx, [rsp+19] )
        Func Call emit_asm (sub rdx, rdi )
        Func Call emit_asm (mov rdi, 1 )
        Func Call emit_asm (syscall )
        Func Call emit_asm (add rsp, 20 )
    )
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(int)
        VarDecl(int)
        (_private_var = 10)
        (__double_underscore = 20)
        (var_with_underscores_ = 70)
        Func Call print_i (((_private_var + __double_underscore) + var_with_underscores_) )
        return( 0 )
    )
)
*/
#include <print>
int main() {
    int _private_var;
    int __double_underscore;
    int var_with_underscores_;
    _private_var = 10;
    __double_underscore = 20;
    var_with_underscores_ = 70;
    print_i(_private_var + __double_underscore + var_with_underscores_);
    return 0;
}
