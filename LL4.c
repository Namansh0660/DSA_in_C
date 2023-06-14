#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void insert_end()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    int val;
    printf("\nEnter data: ");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}
void display()
{
    struct node *ptr=head;
    printf("\nElements in list are: \n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void move_to_last() {
    if(head==NULL|| head->next==NULL)
    {
        return;
    }
    struct node *first,*last;
    first=head;
    last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    head=first->next;
    first->next=NULL;
    last->next=first;
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter choice\n1.Insert \n2.Display \n3.Move to last\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_end();break;
            case 2:display();break;
            case 3:move_to_last();break;
            case 4:exit(0);
        }
    }
    return 0;
}