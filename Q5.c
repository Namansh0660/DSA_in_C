//Reverse stack elements using recursion
#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size],top=-1;
void push(int val)
{
	top++;
	stack[top]=val;
}
void pop()
{
	top--;
}
void display()
{
	for(int i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
}
void insert_at_bottom(int x)
{
	if(top==-1)
	push(x);
	else
	{
		int b=stack[top];
		pop();
		insert_at_bottom(x);
		push(b);
	}
}
void reverse()
{
	if(top!=-1)
	{
		int x=stack[top];
		pop();
		reverse();
		insert_at_bottom(x);
	}
}
int main()
{
	int num,nn;
    printf("Enter Values to enter ");
    scanf("%d",&num);
    printf("Enter values : ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&nn);
        push(nn);
    }
	printf("Before reversing \n");
	display();
	printf("\nAfter reversing \n");
	reverse();
	display();
	return 0;
}