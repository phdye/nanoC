/*
Program (
    FunProto foo(VarDecl(int)) (int)
    FuncDecl main() (int) (
        return( Func Call foo (1 ) )
    )
    FuncDecl foo(VarDecl(int)) (int) (
        return( (x + 1) )
    )
)
*/
int foo(int x);
int main() {
    return foo(1);
}
int foo(int x) {
    return x + 1;
}
