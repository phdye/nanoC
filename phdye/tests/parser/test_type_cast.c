/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(char)
        (c = (char)(x))
        return( 0 )
    )
)
*/

int main() {
    int x;
    char c;
    c = (char)x;
    return 0;
}
