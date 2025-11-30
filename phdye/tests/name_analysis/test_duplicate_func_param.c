/*
Semantic error: Variable 'a' is already declared at line 1 column 16
*/
int foo(int a, int a) {
    return a;
}
int main() {
    return 0;
}
