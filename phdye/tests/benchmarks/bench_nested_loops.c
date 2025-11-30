/*
Benchmark: Nested Loop Performance
Measures: Loop overhead, nested control flow
*/
#include <print>

int main() {
    int sum;
    int i;
    int j;
    int k;

    sum = 0;
    i = 0;
    while (i < 50) {
        j = 0;
        while (j < 50) {
            k = 0;
            while (k < 50) {
                sum = sum + 1;
                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    print_i(sum);
    return 0;
}
