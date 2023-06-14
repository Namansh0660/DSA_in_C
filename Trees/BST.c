#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int height(struct Node* root) {
    if (root == NULL) 
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
        } 
    else {
        return rightHeight + 1;
    }
}
int countNodes(struct Node* root) {
    if (root == NULL) 
        return 0;
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return (leftCount + rightCount + 1);
}
struct Node* findMinValueNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* minValueNode = findMinValueNode(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printf("Height of the tree : %d",height(root));
    printf("\n\nNo of Nodes in the tree : %d",countNodes(root));
    printf("\n\nIn-order traversal : ");
    inOrderTraversal(root);
    printf("\n\n");
    printf("Pre-order traversal : ");
    preOrderTraversal(root);
    printf("\n\n");
    printf("Post-order traversal : ");
    postOrderTraversal(root);
    printf("\n\n");
    root = deleteNode(root, 40);
    printf("In-order traversal after deletion : ");
    inOrderTraversal(root);
    printf("\n\n");
    return 0;
}
