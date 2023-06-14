//basic queue implementation for strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
char queue[max][50];
int front = -1, rear = -1;

void enqueue(char item[]) {
    if (rear == max - 1) {
        printf("Queue overflow!\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        strcpy(queue[rear], item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
    }
    else {
        printf("\n%s : has been dequeued.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    }
    else {
        printf("\nQueue contains : \n");
        for (int i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

int main() {
    enqueue("Queue");
    enqueue("Data");
    enqueue("Structure");
    enqueue("For");
    enqueue("String");
    display();
    dequeue();
    display();
    return 0;
}
