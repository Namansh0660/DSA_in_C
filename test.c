#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

int main()
{
    int top = -1, stack[MAX_SIZE];
    int min_stack[MAX_SIZE], min_top = -1;

    // Push operation
    void push(int element)
    {
        if (top == MAX_SIZE - 1)
        {
            printf("Stack Overflow!\n");
            return;
        }
        stack[++top] = element;
        if (min_top == -1 || element <= min_stack[min_top])
        {
            min_stack[++min_top] = element;
        }
    }

    // Pop operation
    void pop()
    {
        if (top == -1)
        {
            printf("Stack Underflow!\n");
            return;
        }
        int popped_element = stack[top--];
        if (popped_element == min_stack[min_top])
        {
            min_top--;
        }
    }

    // getMin operation
    int getMin()
    {
        if (top == -1)
        {
            printf("Stack is empty!\n");
            return -1;
        }
        return min_stack[min_top];
    }

    // Pushing elements to the stack
    push(16);
    push(15);
    push(29);
    push(19);
    push(18);

    // Getting the minimum element in the stack
    int min_val = getMin();
    printf("Minimum element in the stack is %d\n", min_val);

    // Popping two elements from the stack
    pop();
    pop();

    // Getting the minimum element in the stack after popping two elements
    min_val = getMin();
    printf("Minimum element in the stack after popping two elements is %d\n", min_val);

    return 0;
}
