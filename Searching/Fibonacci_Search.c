#include <stdio.h>

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int n, int key) {
    int fib2 = 0; // (m-2)th Fibonacci number
    int fib1 = 1; // (m-1)th Fibonacci number
    int fib = fib2 + fib1; // mth Fibonacci number

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1; // Offset from the first element

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] == key) {
            return i;
        } else if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 == 1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = fibonacciSearch(arr, n, key);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
