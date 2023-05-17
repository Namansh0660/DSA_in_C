#include <stdio.h>
int linearSearch(int arr[], int n, int key) 
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() 
{
    int arr[] = {5, 2, 7, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int result = linearSearch(arr, n, key);
    if (result == -1) 
    {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}
