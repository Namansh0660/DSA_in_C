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

// Function to evaluate a prefix expression
int prefixEvaluation(char* prefix) {
    Stack stack;
    initialize(&stack);
    int i, result, operand1, operand2;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else {
            operand1 = pop(&stack);
            operand2 = pop(&stack);

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
                    printf("Invalid prefix expression.\n");
                    return -1;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

// Main function
int main() {
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    fgets(prefix, MAX_SIZE, stdin);
    prefix[strlen(prefix) - 1] = '\0';  // Remove newline character

    int result = prefixEvaluation(prefix);

    printf("Result: %d\n", result);

    return 0;
}


// Sample Input:

// Enter a prefix expression: *+AB-CD

// Sample Output:

// Result: 9
