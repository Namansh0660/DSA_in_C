#include <stdio.h>

void swap(int* a, int* b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;                                        //take smallest instead of largest 
    int left = 2*i + 1;
    int right = 2*i + 2;
                                                            
    if (left < n && arr[left] > arr[largest]) {             //for descending order just spam > to < in second arrow
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {             //for descending order just spam > to < in second arrow
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
