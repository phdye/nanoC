/*
1
2
3
*/
#include <print>
int classify(int x) {
    if (x < 0) {
        return 1;
    }
    if (x == 0) {
        return 2;
    }
    return 3;
}
int main() {
    print_i(classify(-5));
    print_c('\n');
    print_i(classify(0));
    print_c('\n');
    print_i(classify(5));
    return 0;
}
