/*
Program (
    FuncDecl foo() (int) (
        return( 42 )
    )
    FuncDecl main() (int) (
        return( Func Call foo () )
    )
)
*/

int foo() {
    return 42;
}

int main() {
    return foo();
}
