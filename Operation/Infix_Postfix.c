#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int top;
    char items[MAX_SIZE];
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
void push(Stack* stack, char ch) {
    stack->items[++stack->top] = ch;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->items[stack->top--];
}

// Function to get the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->items[stack->top];
}

// Function to check if a character is an operand
bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert an infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid infix expression.\n");
                return;
            } else {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && getPrecedence(ch) <= getPrecedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Main function
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';  // Remove newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}



// Sample Input:

// Enter an infix expression: (A+B)*C-D/(E+F)

// Sample Output:

// Postfix expression: AB+C*DEF+/-
