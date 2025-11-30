/*
Program (
    FuncDecl doNothing() (void) (
    )
    FuncDecl main() (int) (
        Func Call doNothing ()
        return( 0 )
    )
)
*/

void doNothing() {
}

int main() {
    doNothing();
    return 0;
}
