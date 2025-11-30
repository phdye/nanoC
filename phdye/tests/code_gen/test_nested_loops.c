/*
0,0
0,1
0,2
1,0
1,1
1,2
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
