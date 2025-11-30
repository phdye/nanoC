/*
10
20
*/
#include <print>
struct Point {
    int x;
    int y;
};
int main() {
    struct Point p;
    p.x = 10;
    p.y = 20;
    print_i(p.x);
    print_c('\n');
    print_i(p.y);
    return 0;
}
