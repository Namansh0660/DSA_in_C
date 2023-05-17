#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = ternarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
