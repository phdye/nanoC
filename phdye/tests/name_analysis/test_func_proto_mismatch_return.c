/*
Semantic error: Conflicting return type in function 'foo' at line 5 column 5
*/
int foo(int x);
char foo(int x) {
    return 'a';
}
int main() {
    return 0;
}
