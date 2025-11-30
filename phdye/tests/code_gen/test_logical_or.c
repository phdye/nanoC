/*
0
1
1
1
*/
#include <print>
int main() {
    print_i(0 || 0);
    print_c('\n');
    print_i(0 || 1);
    print_c('\n');
    print_i(1 || 0);
    print_c('\n');
    print_i(1 || 1);
    return 0;
}
