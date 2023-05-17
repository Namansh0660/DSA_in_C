#include <stdio.h>
#include <stdlib.h>

void pigeonholeSort(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];

    // Find the minimum and maximum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a pigeonhole array
    int size = max - min + 1;
    int* pigeonholes = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        pigeonholes[i] = 0;
    }

    // Traverse the input array and increment the count in the pigeonholes
    for (int i = 0; i < n; i++) {
        pigeonholes[arr[i] - min]++;
    }

    // Update the input array with the sorted values from the pigeonholes
    int index = 0;
    for (int i = 0; i < size; i++) {
        while (pigeonholes[i] > 0) {
            arr[index] = i + min;
            pigeonholes[i]--;
            index++;
        }
    }

    // Free memory
    free(pigeonholes);
}

int main() {
    int arr[] = {4, 2, 8, 3, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pigeonholeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
