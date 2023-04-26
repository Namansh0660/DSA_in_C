#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int countLoops() {
    struct Node* e = head;
    struct Node* y = head;
    int loopCount = 0;
    while (e && y && y->next) {
        e = e->next;
        y = y->next->next;
        if (e == y) {
            loopCount++;
            e = e->next;
            while (e != y) {
                e = e->next;
                loopCount++;
            }
            break;
        }
    }
    return loopCount;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    // Creating a loop by connecting the last node to the second node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head->next;
    printf("Number of loops in the linked list: %d\n", countLoops());
    return 0;
}
