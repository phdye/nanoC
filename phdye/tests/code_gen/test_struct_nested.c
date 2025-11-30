/*
1
2
3
4
*/
#include <print>
struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point topLeft;
    struct Point bottomRight;
};
int main() {
    struct Rect r;
    r.topLeft.x = 1;
    r.topLeft.y = 2;
    r.bottomRight.x = 3;
    r.bottomRight.y = 4;
    print_i(r.topLeft.x);
    print_c('\n');
    print_i(r.topLeft.y);
    print_c('\n');
    print_i(r.bottomRight.x);
    print_c('\n');
    print_i(r.bottomRight.y);
    return 0;
}
