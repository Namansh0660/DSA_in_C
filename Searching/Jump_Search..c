#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    while (arr[prev] < key) {
        prev++;

        if (prev == min(step, n)) {
            return -1;
        }
    }

    if (arr[prev] == key) {
        return prev;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = jumpSearch(arr, n, key);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
