/*
Program (
    FuncDecl main() (int) (
        VarDecl(int*)
        VarDecl(int)
        (x = *(p))
        return( 0 )
    )
)
*/

int main() {
    int* p;
    int x;
    x = *p;
    return 0;
}
