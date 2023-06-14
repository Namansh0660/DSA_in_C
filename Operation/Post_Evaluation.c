#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->items[stack->top--];
}

// Function to evaluate a postfix expression
int postfixEvaluation(char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, result, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid postfix expression.\n");
                    return -1;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

// Main function
int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strlen(postfix) - 1] = '\0';  // Remove newline character

    int result = postfixEvaluation(postfix);

    printf("Result: %d\n", result);

    return 0;
}


// Sample Input:

// Enter a postfix expression: 6523+8*+3+*

// Sample Output:

// Result: 288
