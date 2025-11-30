/*
Semantic error: Identifier 'foo' has already been declared in the same scope at line 7 column 4
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
