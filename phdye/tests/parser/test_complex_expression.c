/*
Program (
    FuncDecl main() (int) (
        VarDecl(int)
        VarDecl(int)
        VarDecl(int)
        (result = (((a + b) * (a - b)) / ((a % b) + 1)))
        return( result )
    )
)
*/

int main() {
    int a;
    int b;
    int result;
    result = (a + b) * (a - b) / (a % b + 1);
    return result;
}
