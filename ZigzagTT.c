#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform ZigZag tree traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Create a queue to store the tree nodes
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    bool leftToRight = true;

    // Enqueue the root node
    queue[rear++] = root;

    while (front != rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            // Print the value of the current node
            printf("%d ", current->val);

            // Enqueue the children of the current node based on the level direction
            if (leftToRight) {
                if (current->left != NULL)
                    queue[rear++] = current->left;
                if (current->right != NULL)
                    queue[rear++] = current->right;
            } else {
                if (current->right != NULL)
                    queue[rear++] = current->right;
                if (current->left != NULL)
                    queue[rear++] = current->left;
            }
        }

        // Reverse the level direction
        leftToRight = !leftToRight;
    }
}
