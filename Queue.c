//Queue Implemenation Method_1
#include<stdio.h>
#include<stdlib.h>
int f=0,r=0;
int a[3];
void enqueue()
{
    int x;
    if(r>=3)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnqueue Element : ");
        scanf("%d",&x);
        a[r]=x;
        r++;
    }
}
void dequeue()
{
    int k;
    if(r==0)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nDeqeueued Elemeet is : %d",a[f]);
        r=r-1;
        for(k=f+1;k<=r;k++)
        {
            a[k-1]=a[k];
        }
    }
}
void display()
{
    printf("\nDisplay : ");
    for(int i=f;i<r;i++)
    {
        printf("%d ",a[i]);
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
            enqueue();
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
    } while (ch<4);
}
