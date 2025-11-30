/*
Program (
    FuncDecl main() (int) (
        VarDecl(int[10])
        (arr[0] = 1)
        (arr[1] = 2)
        return( (arr[0] + arr[1]) )
    )
)
*/
int main() {
    int arr[10];
    arr[0] = 1;
    arr[1] = 2;
    return arr[0] + arr[1];
}
