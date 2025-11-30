/*
17
*/
#include <print>
int main() {
    int a;
    int b;
    int result;
    a = 5;
    b = 3;
    result = (a + b) * 2 - a / b + a % b;
    print_i(result);
    return 0;
}
