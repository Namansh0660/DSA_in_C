#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
int findMax(struct Node* head) 
{
    int max = head->data;
    struct Node* current = head->next;
    while (current != NULL) 
    {
        if (current->data > max) 
        {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}
int main() 
{
    int n, i;
    struct Node* head = NULL;
    struct Node* current = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
            current = newNode;
        } 
        else 
        {
            current->next = newNode;
            current = newNode;
        }
    }
    int max = findMax(head);
    printf("Maximum element in the list: %d", max);
    return 0;
}
