/*
Program (
    FuncDecl main() (int) (
        If ((1)) (
            If ((0)) (
                return( 1 )
            )
            Else (
                return( 2 )
            )
        )
        return( 0 )
    )
)
*/

int main() {
    if (1) {
        if (0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}
