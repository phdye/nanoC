/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(char)
        (c = (char)x)
        (x = (int)c)
        return( 0 )
    )
)
*/
int main() {
    int x;
    char c;
    c = (char)x;
    x = (int)c;
    return 0;
}
