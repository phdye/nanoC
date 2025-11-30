/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(int*)
        (p = &(x))
        return( 0 )
    )
)
*/

int main() {
    int x;
    int* p;
    p = &x;
    return 0;
}
