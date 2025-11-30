/*
Semantic error: Invalid argument type for function 'foo' at line 7 column 12
*/
struct S {};
int foo(int a) {
    return a;
}
int main() {
    struct S s;
    return foo(s);
}
