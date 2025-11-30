/*
42
*/
#include <print>
int main() {
    int x;
    int* p;
    x = 42;
    p = &x;
    print_i(*p);
    return 0;
}
