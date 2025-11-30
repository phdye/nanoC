/*
Semantic error: Conflicting type in argument 'x' in function 'foo' at line 5 column 4
*/
int foo(int x);
int foo(char x) {
    return 0;
}
int main() {
    return 0;
}
