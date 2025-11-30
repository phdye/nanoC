/*
Semantic error: Array index must be of integer type at line 5 column 5
*/
int main() {
    int arr[5];
    char* s;
    arr[s] = 5;
    return 0;
}
