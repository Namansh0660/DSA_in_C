#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
void insert_at_end(struct node **head, int data) 
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) 
    {
        *head = new_node;
        new_node->prev = NULL;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
void print_list(struct node *head) 
{
    printf("List: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void reverse_list(struct node **head) 
{
    struct node *temp = NULL;
    struct node *current = *head;
    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) 
    {
        *head = temp->prev;
    }
}
int main() {
    struct node *head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert_at_end(&head, data);
    }
    printf("\nOriginal ");
    print_list(head);
    reverse_list(&head);
    printf("Reversed ");
    print_list(head);
    return 0;
}