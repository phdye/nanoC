/*
Parsing error: Expected ';' after expression statement at line 8 column 20 found Left Brace
*/
#include <print>
int main() {
    int i;
    i = 0;
    while (i < 6) {
        i = i + 1;
        if (i % 2 == 0) {
            continue;
        }
        print_i(i);
        print_c('\n');
    }
    return 0;
}
