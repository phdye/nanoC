/*
Semantic error: Field 'z' does not exist in struct 'Point' at line 7 column 5
*/
struct Point {
    int x;
};
int main() {
    struct Point p;
    p.z = 5;
    return 0;
}
