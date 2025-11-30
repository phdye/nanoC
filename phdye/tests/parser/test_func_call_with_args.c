/*
Program (
    FuncDecl add(VarDecl(int), VarDecl(int)) (int) (
        return( (a + b) )
    )
    FuncDecl main() (int) (
        return( Func Call add (1 2 ) )
    )
)
*/

int add(int a, int b) {
    return a + b;
}

int main() {
    return add(1, 2);
}
