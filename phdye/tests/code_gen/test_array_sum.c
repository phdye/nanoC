/*
15
*/
#include <print>
int main() {
    int arr[5];
    int sum;
    int i;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    sum = 0;
    i = 0;
    while (i < 5) {
        sum = sum + arr[i];
        i = i + 1;
    }
    print_i(sum);
    return 0;
}
