/*
done
*/
#include <print>
int main() {
    int a;
    int b;
    int c;
    a = 0;
    while (a < 2) {
        b = 0;
        while (b < 2) {
            c = 0;
            while (c < 2) {
                c = c + 1;
            }
            b = b + 1;
        }
        a = a + 1;
    }
    print_c('d');
    print_c('o');
    print_c('n');
    print_c('e');
    return 0;
}
