/*
Program (
    StructDecl Point (VarDecl(int))
    FuncDecl main() (int) (
        VarDecl(struct Point)
        ((p.x) = 5)
        return( (p.x) )
    )
)
*/

struct Point {
    int x;
};

int main() {
    struct Point p;
    p.x = 5;
    return p.x;
}
