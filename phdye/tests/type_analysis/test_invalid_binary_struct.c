/*
Semantic error: Invalid operand type for binary operator '+' at line 10 column 8
*/
struct Point {
    int x;
};
int main() {
    struct Point a;
    struct Point b;
    a + b;
    return 0;
}
