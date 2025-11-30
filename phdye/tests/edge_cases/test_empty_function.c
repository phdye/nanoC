/*
Program (
    FuncDecl empty() (void) (
    )
    FuncDecl main() (int) (
        Func Call empty ( )
        return( 0 )
    )
)
*/
void empty() {}
int main() {
    empty();
    return 0;
}
