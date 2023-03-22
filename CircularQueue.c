//Circular queue implementation
#include<stdio.h>
#include<stdlib.h>
#define size 5
int ar[size];
int front=-1,rear=-1;
void enqueue(int val)
{
    if((rear+1)%size==front)
        printf("Queue is Full");
    else
    {
        rear=(rear+1)%size;
        ar[rear]=val;
        if(front==-1)
            front=rear;
    }
}
int dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return 0;
    }
    else
    {
        int val=ar[front];
        if(front=rear)
            front=rear=-1;
        else
            front=(front+1)%size;
        return val;
    }
}
void display()
{
    if(front==-1 && rear==-1)
        printf("Queue underflow");
    if(front>rear)
    {
        for(int i=front;i<size-1;i++)
        {
            printf("%d "+ar[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d "+ar[i]);
        }
        printf("\nrear is at %d\n",ar[rear]);
        printf("\nfront is at %d\n",ar[front]);
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",ar[i]);
        }
        printf("\nrear is at %d\n",ar[rear]);
        printf("\nfront is at %d\n",ar[front]);
    }
    printf("\n");
}
int main()
{
    int ch;
    while(1)
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
    }
}
