/*
Semantic error: Cannot access member of non-struct type at line 4 column 5
*/
int main() {
    int x;
    x.field = 5;
    return 0;
}
