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
    FuncDecl classify(VarDecl(int)) (int) (
        If ((x < 0)) (
            return( 1 )
        )

        If ((x == 0)) (
            return( 2 )
        )

        return( 3 )
    )
    FuncDecl main() (int) (
        Func Call print_i (Func Call classify (-(5) ) )
        Func Call print_c (10 )
        Func Call print_i (Func Call classify (0 ) )
        Func Call print_c (10 )
        Func Call print_i (Func Call classify (5 ) )
        return( 0 )
    )
)
*/
#include <print>
int classify(int x) {
    if (x < 0) {
        return 1;
    }
    if (x == 0) {
        return 2;
    }
    return 3;
}
int main() {
    print_i(classify(-5));
    print_c('\n');
    print_i(classify(0));
    print_c('\n');
    print_i(classify(5));
    return 0;
}
