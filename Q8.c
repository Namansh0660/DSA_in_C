//Sorting using recursion(characters)
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
char c;
int n,i;
void push(char data) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    char data = stack[top--];
    return data;
}
char peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}
void insert_sorted(char data) {
    if (top == -1 || data > peek()) {
        push(data);
        return;
    }
    char temp = pop();
    insert_sorted(data);
    push(temp);
}
void sort_stack() {
    if (top == -1) {
        return;
    }
    char temp = pop();
    sort_stack();
    insert_sorted(temp);
}
void reverse_stack() {
    int i, j;
    char temp;
    for (i = 0, j = top; i < j; i++, j--) {
        temp = stack[i];
        stack[i] = stack[j];
        stack[j] = temp;
    }
}
void print_stack() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}
int main() {
    char c;
    int n,i;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    printf("Enter %d characters: ", n);
    for (i = 0; i< n; i++) {
        scanf(" %c", &c);
        push(c);
    }
    printf("Stack before sorting: ");
    print_stack();
    sort_stack();
    printf("Stack after sorting: ");
    reverse_stack();
    print_stack();
    return 0;
}