/*
Semantic error: Function 'foo' was previously declared with conflicting type at line 3 column 5
*/
int foo(int x);
int foo(char x) {
    return 0;
}
int main() {
    return 0;
}
