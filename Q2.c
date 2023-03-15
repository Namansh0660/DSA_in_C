//Basic stack operations using array for characters
#include<stdio.h>
#include<stdlib.h>
#define size 5
char stack[size],top=-1,n,var,choice;
void push()
{
    if((top+1)==n)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter the number of element\n");
        scanf("%s",&var);
        stack[++top]=var;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        top--;
    }
}
void show()
{
    for(int i=top;i>=0;i--)
    {
        printf("\n%c",stack[i]);
    }
    if(top==-1)
    {
        printf("\nStack Empty\n");
    }
}
int main()
{
    printf("\nEnter the number of element\n");
    scanf("%d",&n);
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