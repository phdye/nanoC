/*
Benchmark: Struct Field Access
Measures: Struct member access overhead
*/
#include <print>

struct Point {
    int x;
    int y;
    int z;
};

int main() {
    struct Point points[100];
    int i;
    int sum;

    // Initialize
    i = 0;
    while (i < 100) {
        points[i].x = i;
        points[i].y = i * 2;
        points[i].z = i * 3;
        i = i + 1;
    }

    // Sum all fields
    sum = 0;
    i = 0;
    while (i < 100) {
        sum = sum + points[i].x + points[i].y + points[i].z;
        i = i + 1;
    }

    print_i(sum);
    return 0;
}
