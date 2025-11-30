/*
Semantic error: Left operand of '.' operator must be a structure but found 'int' at line 6 column 7
*/
int main() {
    int x;
    x.field = 5;
    return 0;
}
