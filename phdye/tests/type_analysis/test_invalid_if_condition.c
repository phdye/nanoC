/*
Semantic error: Condition expression must be of type 'int' or pointer at line 6 column 9
*/
struct S {};
int main() {
    struct S s;
    if (s) {
        return 1;
    }
    return 0;
}
