#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void inOrderTraversal(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left, arr, index);
    arr[(*index)++] = root->data;
    inOrderTraversal(root->right, arr, index);
}

void treeSort(int arr[], int n) {
    struct TreeNode* root = NULL;
    
    for (int i = 0; i < n; i++) {
        insert(&root, arr[i]);
    }

    int index = 0;
    inOrderTraversal(root, arr, &index);

    // Free memory allocated for the tree
    // (if you don't need the sorted array in the original array)
    // free(root);
}

int main() {
    int arr[] = {7, 3, 9, 2, 6, 4, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    treeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
