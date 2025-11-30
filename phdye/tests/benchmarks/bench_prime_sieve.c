/*
Benchmark: Prime Sieve (Eratosthenes)
Measures: Array operations, loop performance
*/
#include <print>

int main() {
    int sieve[100];
    int i;
    int j;
    int count;

    // Initialize sieve
    i = 0;
    while (i < 100) {
        sieve[i] = 1;
        i = i + 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;

    // Sieve algorithm
    i = 2;
    while (i * i < 100) {
        if (sieve[i] == 1) {
            j = i * i;
            while (j < 100) {
                sieve[j] = 0;
                j = j + i;
            }
        }
        i = i + 1;
    }

    // Count primes
    count = 0;
    i = 0;
    while (i < 100) {
        if (sieve[i] == 1) {
            count = count + 1;
        }
        i = i + 1;
    }

    print_i(count);
    return 0;
}
