/*
Semantic error: Array index must be an integer type but found 'char*' at line 7 column 9
*/
int main() {
    int arr[5];
    char* s;
    arr[s] = 5;
    return 0;
}
