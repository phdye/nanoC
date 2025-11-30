/*
Semantic error: Function 'foo' is already declared at line 6 column 5
*/
int foo() {
    return 1;
}
int foo() {
    return 2;
}
int main() {
    return 0;
}
