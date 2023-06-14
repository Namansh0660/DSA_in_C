#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
int countElements(struct Node* head) 
{
    int count = 0;
    struct Node* current = head;    
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }
    return count;
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
    int count = countElements(head);
    printf("Total number of elements in the list: %d", count);
    return 0;
}
