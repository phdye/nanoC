/*
Benchmark: Function Call Overhead
Measures: Function call, parameter passing, return values
*/
#include <print>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int compute(int x) {
    return add(multiply(x, x), x);
}

int main() {
    int i;
    int result;

    result = 0;
    i = 0;
    while (i < 1000) {
        result = add(result, compute(i % 10));
        i = i + 1;
    }

    print_i(result);
    return 0;
}
