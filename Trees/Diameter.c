#include <stdio.h>
#include <stdlib.h>
struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int value) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int getHeight(struct TreeNode* root) 
{
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int diameter(struct TreeNode* root) 
{
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
}
int main() 
{
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int dia = diameter(root);
    printf("Diameter of the binary tree: %d\n", dia);
    return 0;
}
