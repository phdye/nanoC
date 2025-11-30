/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        (x = 1)
        (
            VarDecl(int)
            (x = 2)
        )
        return( x )
    )
)
*/
int main() {
    int x;
    x = 1;
    {
        int x;
        x = 2;
    }
    return x;
}
