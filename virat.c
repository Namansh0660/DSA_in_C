#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node *right;
};
struct node * createnode(int val)
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node * insert(struct node * root,int val){
    if(root == NULL)
    return createnode(val);
    if(val < root->data)
    root->left = insert(root->left , val);
    else {
        root->right = insert(root->right,val);
    }
    return root;
}
struct node * findcommonancestor(struct node * root ,int node1 ,int node2)
{
    if(root == NULL)
    return NULL;
    if(node1>root->data&&node2>root->data)
    return findcommonancestor(root->right,node1,node2);
    if (node1<root->data&& node2<root->data)
    return findcommonancestor(root->left,node1,node2);
}
int  finddistance(struct node * root,int val)
{
    if(root == NULL)
   { return 0;}
    if(val == root->data )
   { return 0;}
    else if(val < root->data)
    {
       return 1+finddistance(root->left,val); 
    }
    else
    {
        return 1+ finddistance(root->right,val);
    }
}
int shorttestnode (struct node * root,int node1,int node2)
{
    struct node * commonnode = findcommonancestor(root,node1,node2);
    int d1 = finddistance(commonnode,node1);
    int d2 = finddistance(commonnode,node2);
    return d1+d2;
}
int main(){
     struct node *root = NULL;
    root = insert(root,1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    printf("fsdfes");
    insert(root, 11);
    insert(root, 15);
  // int distance = shortdistance(root, 1,15);
    printf("The distance between nodes is: %d\n",  shorttestnode(root, 10,4));
    return 0;
}
// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int data;
//     struct node *left, *right;
// };

// struct node* getnode(int val) {
//     struct node *newnode = malloc(sizeof(struct node));
//     newnode->data = val;
//     newnode->left = NULL;
//     newnode->right = NULL;
//     return newnode;
// }

// struct node* insert(struct node *root, int val) {
//     if (root == NULL) {
//         return getnode(val);
//     }
//     if (val < root->data) {
//         root->left = insert(root->left, val);
//     }
//     else {
//         root->right = insert(root->right, val);
//     }
//     return root;
// }

// struct node* findcommonparent(struct node *root, int node1, int node2) {
//     if (root == NULL) {
//         return NULL;
//     }
//     if (node1 > root->data && node2 > root->data) {
//         return findcommonparent(root->right, node1, node2);
//     }
//     if (node1 < root->data && node2 < root->data) {
//         return findcommonparent(root->left, node1, node2);
//     }
//     return root;
// }

// int finddistance(struct node *root, int val) {
//     if (root == NULL) {
//         return 0;
//     }
//     if (val == root->data) {
//         return 0;
//     }
//     else if ( val < root->data) {
//         return 1 + finddistance(root->left, val);
//     }
//     else {
//         return 1 + finddistance(root->right, val);
//     }
// }

// int shortestdistance(struct node *root, int node1, int node2) {
//     struct node *commonancestor = findcommonparent(root, node1, node2);
//     int d1 = finddistance(commonancestor, node1);
//     int d2 = finddistance(commonancestor, node2);
//     return d1 + d2;
// }

// int main() {
//     struct node *root = NULL;
//     root = insert(root, 1);
//     insert(root, 2);
//     insert(root, 3);
//     insert(root, 4);
//     insert(root, 5);
//     //insert(root, 1);
//     insert(root, 6);
//  //   insert(root, 4);
//     insert(root, 7);

//     int distance = shortestdistance(root, 1, 7);
//     printf("The distance between nodes is: %d\n", distance);
//     return 0;
// }