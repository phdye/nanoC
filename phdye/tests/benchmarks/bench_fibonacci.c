/*
Benchmark: Recursive Fibonacci
Measures: Function call overhead, recursion performance
*/
#include <print>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int i;
    int result;
    i = 0;
    while (i < 30) {
        result = fib(i);
        i = i + 1;
    }
    print_i(result);
    return 0;
}
