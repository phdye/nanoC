/*
Semantic error: Condition expression must be of type 'int' or pointer at line 6 column 12
*/
struct S {};
int main() {
    struct S s;
    while (s) {
        break;
    }
    return 0;
}
