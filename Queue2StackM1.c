// Queue using two stacks Method 1 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stack[SIZE][2];
int top[2] = {-1, -1};
void push(int stack_num, int x) 
{
  if (top[stack_num] == SIZE - 1) 
  {
    printf("Stack Overflow!\n");
    return;
  }
  top[stack_num]++;
  stack[top[stack_num]][stack_num] = x;
}
int pop(int stack_num) 
{
  if (top[stack_num] == -1) 
  {
    printf("Stack Underflow!\n");
    return -1;
  }
  int x = stack[top[stack_num]][stack_num];
  top[stack_num]--;
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
    push(1, pop(0)); 
  }
}
int deQueue() 
{
  if (top[1] == -1) 
  {
    transfer();
  }
  return pop(1); 
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
