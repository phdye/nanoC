/*
Semantic error: Field 'x' is already declared in struct at line 4 column 9
*/
struct Point {
    int x;
    int x;
};
int main() {
    return 0;
}
