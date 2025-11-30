/*
Semantic error: Invalid argument count for function 'foo' at line 6 column 12
*/
int foo(int a, int b) {
    return a + b;
}
int main() {
    return foo(1);
}
