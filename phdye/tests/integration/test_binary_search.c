/*
4
*/
#include <print>
int binarySearch(int* arr, int size, int target) {
    int left;
    int right;
    int mid;
    left = 0;
    right = size - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[10];
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 7;
    arr[4] = 9;
    arr[5] = 11;
    arr[6] = 13;
    arr[7] = 15;
    arr[8] = 17;
    arr[9] = 19;
    print_i(binarySearch(arr, 10, 9));
    return 0;
}
