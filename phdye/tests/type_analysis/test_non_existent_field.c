/*
Semantic error: Struct 'Point' has no member named 'z' at line 9 column 7
*/
struct Point {
    int x;
};
int main() {
    struct Point p;
    p.z = 5;
    return 0;
}
