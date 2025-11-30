/*
Program (
    StructDecl Empty (
    )
    FuncDecl main() (int) (
        VarDecl(struct Empty)
        return( 0 )
    )
)
*/
struct Empty {};
int main() {
    struct Empty e;
    return 0;
}
