//Sorting using recursion(numbers)
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE],num,nn,top=-1;
void push(int data)
{
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}
int pop()
{
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
int peek()
{
    if (top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}
int is_empty()
{
    return top == -1;
}
void insert_sorted(int data)
{
    if (is_empty() || data > peek()) {
        push(data);
        return;
    }
    int temp = pop();
    insert_sorted(data);
    push(temp);
}
void sort_stack()
{
    if (is_empty()) {
        return;
    }
    int temp = pop();
    sort_stack();
    insert_sorted(temp);
}
void print_stack()
{
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    printf("Enter Values to enter : ");
    scanf("%d",&num);
    printf("Enter values : ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&nn);
        push(nn);
    }
    printf("\nBefore sorting: \n");
    print_stack();
    sort_stack();
    printf("\nAfter sorting: \n");
    print_stack();
    return 0;
}
