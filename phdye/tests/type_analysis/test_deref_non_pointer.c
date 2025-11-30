/*
Semantic error: Dereferencing non-pointer 'int' at line 6 column 10
*/
int main() {
    int x;
    x = *x;
    return 0;
}
