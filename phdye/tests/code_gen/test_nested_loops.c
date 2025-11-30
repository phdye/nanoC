/*
Parsing error: Expected ';' after expression statement at line 9 column 20 found Left Brace
*/
#include <print>
int main() {
    int i;
    int j;
    i = 0;
    while (i < 2) {
        j = 0;
        while (j < 3) {
            print_i(i);
            print_c(',');
            print_i(j);
            print_c('\n');
            j = j + 1;
        }
        i = i + 1;
    }
    return 0;
}
