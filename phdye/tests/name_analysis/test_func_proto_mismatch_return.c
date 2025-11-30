/*
Semantic error: Function 'foo' was previously declared with conflicting type at line 3 column 6
*/
int foo(int x);
char foo(int x) {
    return 'a';
}
int main() {
    return 0;
}
