/*
Parsing error: Expected ';' after expression statement at line 7 column 16 found Left Brace
*/
struct S {};
int main() {
    struct S s;
    while (s) {
        break;
    }
    return 0;
}
