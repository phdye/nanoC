/*
Semantic error: Invalid type cast from 'int' to 'char' at line 7 column 14
*/
int main() {
    int x;
    char c;
    c = (char)x;
    x = (int)c;
    return 0;
}
