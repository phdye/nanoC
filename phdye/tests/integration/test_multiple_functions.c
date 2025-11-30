/*
Parsing error: Expected ';' after expression statement at line 16 column 21 found Left Brace
*/
#include <print>
int square(int x) {
    return x * x;
}
int cube(int x) {
    return x * square(x);
}
int sumOfCubes(int n) {
    int sum;
    int i;
    sum = 0;
    i = 1;
    while (i <= n) {
        sum = sum + cube(i);
        i = i + 1;
    }
    return sum;
}
int main() {
    print_i(sumOfCubes(3));
    return 0;
}
