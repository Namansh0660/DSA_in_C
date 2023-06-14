// ZigZag Tree Traversal using DFS method

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void zigzagTraversalDFS(struct TreeNode* root, int level, bool leftToRight) 
{
    if (root == NULL)
        return;
    if (level == 1) 
    {
        printf("%d ", root->val);
    } 
    else if (level > 1) 
    {
        if (leftToRight) 
        {
            zigzagTraversalDFS(root->left, level - 1, leftToRight);
            zigzagTraversalDFS(root->right, level - 1, leftToRight);
        } 
        else 
        {
            zigzagTraversalDFS(root->right, level - 1, leftToRight);
            zigzagTraversalDFS(root->left, level - 1, leftToRight);
        }
    }
}
int getHeight(struct TreeNode* root) 
{
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
void zigzagTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;
    int height = getHeight(root);
    bool leftToRight = true;
    for (int level = 1; level <= height; level++) 
    {
        zigzagTraversalDFS(root, level, leftToRight);
        leftToRight = !leftToRight;
    }
}
int main() 
{
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("ZigZag traversal: ");
    zigzagTraversal(root);
    printf("\n");
    return 0;
}
