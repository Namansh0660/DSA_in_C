//Basic stack operations using structure
#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
    int stack[size];
    int top;
    int n;
}s;
void push()
{
    int var;
    if((s.top+1)==s.n)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter the number of element\n");
        scanf("%d",&var);
        s.stack[++s.top]=var;
    }
}
void pop()
{
    if(s.top==-1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        s.top--;
    }
}
void show()
{
    for(int i=s.top;i>=0;i--)
    {
        printf("\n%d",s.stack[i]);
    }
    if(s.top==-1)
    {
        printf("\nStack Empty\n");
    }
}
int main()
{
    int choice;
    s.top=-1;
    printf("\nEnter the number of element\n");
    scanf("%d",&s.n);
    while(choice!=4)
    {
        printf("\nChose Your option...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                show();
                break;
            }
            case 4:
            {
                printf("Exiting....");
                exit(0);
                break;
            }
            default:
            {
                printf("Please Enter Valid Choice");
            }
        }
    }
    return 0;
}