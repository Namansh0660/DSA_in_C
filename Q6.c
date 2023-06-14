//Sorting using another stack(numbers)
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int aux_stack[MAX_SIZE];
int top = -1;
void push(int data) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}
int pop() 
{
    if (top == -1) 
    {
        printf("Empty Stack!\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}
void sort_stack() 
{
    int temp;
    int aux_top = -1;

    while (top != -1) 
    {
        temp = pop();
        while (aux_top != -1 && aux_stack[aux_top] < temp) 
        {
            push(aux_stack[aux_top]);
            aux_top--;
        }
        aux_top++;
        aux_stack[aux_top] = temp;
    }
    while (aux_top != -1) 
    {
        push(aux_stack[aux_top]);
        aux_top--;
    }
}
int main() 
{
    int num,nn;
    printf("Enter Values to enter ");
    scanf("%d",&num);
    printf("Enter values : ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&nn);
        push(nn);
    }
    printf("Original stack: ");
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    sort_stack();
    printf("Sorted stack: ");
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}
