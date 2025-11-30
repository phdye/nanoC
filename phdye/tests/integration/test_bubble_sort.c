/*
Parsing error: Expected ';' after expression statement at line 16 column 20 found Left Brace
*/
#include <print>
int main() {
    int arr[5];
    int i;
    int j;
    int temp;
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 1;
    arr[4] = 3;
    i = 0;
    while (i < 5) {
        j = 0;
        while (j < 4 - i) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < 5) {
        print_i(arr[i]);
        print_c('\n');
        i = i + 1;
    }
    return 0;
}
