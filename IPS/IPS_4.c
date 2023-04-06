#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;
void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
int pop()
{
    if(top==NULL)
    {
        return -1;
    }
    struct node*temp=top;
    int n=temp->data;
    top=top->next;
    free(temp);
    return n;
}
void display()
{
    struct node*i;
    for(i=top;i!=NULL;i=i->next)
    {
        printf("%d ",i->data);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int value=0;
        scanf("%d\n",&value);
        push(value);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",pop());
    }
}
