// Queue using two stacks Method 2
#include <stdio.h>
#define SIZE 10
int stack[SIZE][2];
int top[2] = {-1, -1};
void push(int stack_num, int x) 
{
    if (top[stack_num] == SIZE-1) 
    {
        printf("Stack %d Overflow\n", stack_num);
    } 
    else 
    {
        top[stack_num]++;
        stack[top[stack_num]][stack_num] = x;
    }
}
int pop(int stack_num) 
{
    int x = -1;
    if (top[stack_num] == -1) 
    {
        printf("Stack %d Underflow\n", stack_num);
    } 
    else 
    {
        x = stack[top[stack_num]][stack_num];
        top[stack_num]--;
    }
    return x;
}
void enQueue(int x) 
{
    push(0, x);
}
void transfer() 
{
    while (top[0] != -1) 
    {
        int x = pop(0);
        push(1, x);
    }
}
int deQueue() 
{
    int bottom_element = -1;
    if (top[0] == -1) 
    {
        printf("Queue Underflow\n");
    } 
    else 
    {
        transfer();
        bottom_element = pop(1);
        while (top[1] != -1) 
        {
            int x = pop(1);
            push(0, x);
        }
    }
    return bottom_element;
}
int main() 
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    printf("%d\n", deQueue()); 
    printf("%d\n", deQueue()); 
    enQueue(40);
    printf("%d\n", deQueue()); 
    printf("%d\n", deQueue()); 
    printf("%d\n", deQueue());
    return 0;
}
