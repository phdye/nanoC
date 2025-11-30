/*
Semantic error: Identifier 'a' has already been declared in the same scope at line 4 column 19
*/
int foo(int a, int a) {
    return a;
}
int main() {
    return 0;
}
