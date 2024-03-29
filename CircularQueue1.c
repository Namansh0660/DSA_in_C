//Circular queue implementation
#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max],front=0,rear=-1;
void insert();
void delete();
void display();
int main()
{
    int ch;
    printf("\nCircular Queue operations\n");
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            insert();
            break;

            case 2 :
            delete();
            break;

            case 3 : 
            display();
            break;

            case 4 :
            exit(0);
            break; 

            default : 
            printf("\nWrong Input");
        }
    }
    return 0;
}
void insert()
{
    int x;
    if(((front==0) && (rear==max-1)) || (front>0 && rear==front-1))
    {
        printf("Queue is overflow");
    }
    else
    {
        printf("Enter Element to be inserted : ");
        scanf("%d",&x);
        if(rear==max-1 && front>0)
        {
            rear=0;
            q[rear]=x;
        }
        else
        {
            if((front==0&&rear==-1)||(rear!=front-1))
            {
                q[++rear]=x;
            }
        }
    }
}
void delete()
{
    int a;
    if((front==0)&&(rear==-1))
    {
        printf("Queue is underflow\n");
        exit(0);
    }
    if(front==rear)
    {
        a=q[front];
        rear=-1;
        front=0;
    }
    else
    {
        if(front==max-1)
        {
            a=q[front];
            front=0;
        }
        else
        {
            a=q[front++];
        }
    }
    printf("Deleted element is : %d\n",a);
}
void display()
{
    int i,j;
    if((front==0)&&(rear==-1))
    {
        printf("Queue is underflow\n");
        exit(0);
    }
    if(front>rear)
    {
        for(j=front;j<=max-1;j++)
        {
            printf("\t%d",q[j]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
        printf("\nrear is at %d\n",q[rear]);
        printf("\nfront is at %d\n",q[front]);
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
        printf("\nrear is at %d\n",q[rear]);
        printf("\nfront is at %d\n",q[front]);
    }
    printf("\n");
}