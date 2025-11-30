/*
Parsing error: Expected ';' after expression statement at line 8 column 20 found Left Brace
*/
#include <print>
int main() {
    int i;
    i = 0;
    while (i < 5) {
        print_i(i);
        print_c('\n');
        i = i + 1;
    }
    return 0;
}
