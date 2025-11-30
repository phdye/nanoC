/*

*/
struct S {};
int foo(int a) {
    return a;
}
int main() {
    struct S s;
    return foo(s);
}
