// Queue using single stack(recursion)
#include <stdio.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int value) 
{
    if (top == SIZE - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}
void enQueue(int value) 
{
    push(value);
}
int getBottom() 
{
    int value = pop();
    if (top == -1) 
    {
        return value;
    }
    int bottom = getBottom(); 
    push(value);
    return bottom;
}
int deQueue() 
{
    return getBottom(); 
}
int main() 
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    printf("%d\n", deQueue());
    printf("%d\n", deQueue());
    printf("%d\n", deQueue());
    return 0;
}
