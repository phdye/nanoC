/*
100
*/
#include <print>
int main() {
    int x;
    int* p;
    x = 42;
    p = &x;
    *p = 100;
    print_i(x);
    return 0;
}
