/*

*/
struct S {};
int main() {
    struct S s;
    if (s) {
        return 1;
    }
    return 0;
}
