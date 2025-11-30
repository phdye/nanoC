/*
1
0
1
0
1
*/
#include <print>
int isPrime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    i = 3;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i = i + 2;
    }
    return 1;
}
int main() {
    print_i(isPrime(2));
    print_c('\n');
    print_i(isPrime(4));
    print_c('\n');
    print_i(isPrime(17));
    print_c('\n');
    print_i(isPrime(18));
    print_c('\n');
    print_i(isPrime(97));
    return 0;
}
