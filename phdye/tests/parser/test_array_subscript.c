/*
Program (
    FuncDecl main() (int) (
        VarDecl(int*)
        ((arr[0]) = 10)
        return( (arr[0]) )
    )
)
*/

int main() {
    int arr[5];
    arr[0] = 10;
    return arr[0];
}
