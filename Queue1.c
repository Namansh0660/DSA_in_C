//Queue Implemenation Method_2
#include<stdio.h>
#include<stdlib.h>
#define size 5
int f=-1,r=-1;
int a[size];
void enqueue(int val)
{
    if(r==size-1)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
       r++;
        a[r]=val;
        printf("\nEnqueued Element : %d",val);
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nDeqeueued Element is : %d",a[f]);
        f++;
        if(f>r)
        {
            f=r=-1;
        }
    }
}
void display()
{
    if(r==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nDisplay : ");
        for(int i=f;i<=r;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit...");
        printf("\nEnter your option : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            int val;
            scanf("%d",&val);
            enqueue(val);
            break;
            
            case 2 :
            dequeue();
            break;
            
            case 3 :
            display();
            break;

            case 4 :
            exit(0);

            default : 
            printf("wrong input");
            exit(0);
        }
    } while (ch<5);
}
