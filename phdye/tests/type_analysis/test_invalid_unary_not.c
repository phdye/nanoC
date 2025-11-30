/*
Semantic error: Invalid operand type for unary operator '!' at line 6 column 12
*/
struct S {};
int main() {
    struct S s;
    return !s;
}
