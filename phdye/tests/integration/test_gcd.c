/*
6
*/
#include <print>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    print_i(gcd(48, 18));
    return 0;
}
