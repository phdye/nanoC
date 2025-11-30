/*

*/
int main() {
    int x;
    int* p;
    p = &x;
    *p = 42;
    return *p;
}
