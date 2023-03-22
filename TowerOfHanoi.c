//Tower of hanoi using stack
#include <stdio.h>
#define size 100
int A[size], aTop=-1;
int B[size], bTop=-1;
int C[size], cTop=-1;
void push(int x, int *top, int stack[]) 
{
    if(*top==(size-1)) 
    {
        printf("Stack overflow\n");
        return;
    }
    *top=*top+1;
    stack[*top] = x;
}
int pop(int *top, int stack[]) 
{
    int holder;
    if(*top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    holder = stack[*top];
    *top=*top-1;
    return holder;
}
void displayStack(int top, int stack[]) 
{
    if (top==-1) 
    {
        printf("(empty)\n");
        return;
    }
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void rods() {
    printf("stack A: ");
    displayStack(aTop, A);
    printf("stack B: ");
    displayStack(bTop, B);
    printf("stack C: ");
    displayStack(cTop, C);
    printf("\n");
}
void towerOfHanoi(int n,char from_rod, char to_rod, char aux_rod, int A[], int C[], int B[], int *aTop, int *cTop, int *bTop)
    {
    if(n==1)
    {
        printf("Moving disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        push(pop(aTop, A), cTop, C);
        return;
    }
    towerOfHanoi(n-1,from_rod,aux_rod,to_rod, A, B, C, aTop, bTop, cTop);
    printf("Moving disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    push(pop(aTop, A), cTop, C);
    towerOfHanoi(n-1,aux_rod,to_rod,from_rod, B, C, A, bTop, cTop, aTop);
}
int main()
{
    int n;
    printf("Enter number of disks on source pole (Stack A):");
    scanf("%d", &n);
    for (int i = n; i>0; i--) 
    {
        push(i, &aTop, A);
    }
    printf("\nBefore moving: \n");
    rods();
    printf("Moves: \n");
    towerOfHanoi(n, 'A', 'C', 'B', A, C, B, &aTop, &cTop, &bTop);
    printf("\nAfter moving: \n");
    rods();
    return 0;
}