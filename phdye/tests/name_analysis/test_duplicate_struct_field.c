/*
Semantic error: Identifier 'x' has already been declared in the same scope at line 6 column 8
*/
struct Point {
    int x;
    int x;
};
int main() {
    return 0;
}
