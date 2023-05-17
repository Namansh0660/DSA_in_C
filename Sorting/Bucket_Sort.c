#include <stdio.h>
#include <stdlib.h>

// Structure for each bucket
struct Bucket {
    int count;
    int* values;
};

void bucketSort(int arr[], int n) {
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

    int numBuckets = max - min + 1;

    // Create buckets
    struct Bucket* buckets = (struct Bucket*)malloc(numBuckets * sizeof(struct Bucket));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].count = 0;
        buckets[i].values = NULL;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;

        buckets[index].count++;
        buckets[index].values = (int*)realloc(buckets[index].values, buckets[index].count * sizeof(int));
        buckets[index].values[buckets[index].count - 1] = arr[i];
    }

    // Sort individual buckets and update the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].count > 0) {
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index] = buckets[i].values[j];
                index++;
            }
            free(buckets[i].values);
        }
    }

    // Free memory
    free(buckets);
}

int main() {
    int arr[] = {4, 2, 8, 3, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
