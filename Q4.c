//Reverse stack elements using another stack
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
   if (top == MAX_SIZE - 1) {
      printf("Stack is full");
   } else {
      top++;
      stack[top] = item;
   }
}

int pop() {
   int item;
   if (top == -1) {
      printf("Stack is empty");
   } else {
      item = stack[top];
      top--;
      return item;
   }
   return -1;
}

int isempty() {
   if (top == -1)
      return 1;
   else
      return 0;
}

int isfull() {
   if (top == MAX_SIZE - 1)
      return 1;
   else
      return 0;
}

void reverse() {
   int tempStack[MAX_SIZE];
   int tempTop = -1;
   int size = top + 1;

   while (!isempty()) {
      int item = pop();
      tempTop++;
      tempStack[tempTop] = item;
   }

   for (int i = 0; i < size; i++) {
      int item = tempStack[i];
      push(item);
   }
}
void show()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    if(top==-1)
    {
        printf("\nStack Empty\n");
    }
}
int main() {
   int num, nn;
   printf("Enter number of values to enter: ");
   scanf("%d", &num);
   printf("Enter values: ");
   for (int i = 0; i < num; i++) {
      scanf("%d", &nn);
      push(nn);
   }
   printf("Stack before reversal: ");
   show();
   printf("\nStack after reversal: ");
   reverse();
   show();
   return 0;
}
