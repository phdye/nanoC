/*
Semantic error: Too few/many arguments in function 'foo' call at line 8 column 15
*/
int foo(int a, int b) {
    return a + b;
}
int main() {
    return foo(1);
}
