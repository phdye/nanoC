/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(int*)
        (p = &x)
        (*p = 42)
        return( *p )
    )
)
*/
int main() {
    int x;
    int* p;
    p = &x;
    *p = 42;
    return *p;
}
