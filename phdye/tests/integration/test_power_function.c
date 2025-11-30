/*
Parsing error: Expected ';' after expression statement at line 8 column 22 found Left Brace
*/
#include <print>
int power(int base, int exp) {
    int result;
    result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exp = exp / 2;
    }
    return result;
}
int main() {
    print_i(power(2, 10));
    return 0;
}
