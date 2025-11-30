/*
Parsing error: Expected ';' after expression statement at line 8 column 21 found Left Brace
*/
#include <print>
int main() {
    int i;
    i = 0;
    while (i < 10) {
        print_i(i);
        print_c('\n');
        if (i == 2) {
            break;
        }
        i = i + 1;
    }
    return 0;
}
