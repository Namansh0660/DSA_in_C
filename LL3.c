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
void move_to_front() {
    if(head==NULL|| head->next==NULL)
    {
        return;
    }
    struct node *secondlast,*last;
    secondlast=head;
    last=head;
    while(last->next!=NULL)
    {
        secondlast=last;
        last=last->next;
    }
    secondlast->next=NULL;
    last->next=head;
    head=last;
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter choice\n1.Insert \n2.Display \n3.Move to front\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_end();break;
            case 2:display();break;
            case 3:move_to_front();break;
            case 4:exit(0);
        }
    }
    return 0;
}