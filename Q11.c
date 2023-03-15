//Infix to postfix using stack
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char stack[10];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
        exit(0);
    else
        return stack[top--];
}
int priority(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
int main()
{
    char exp[100];
    char *e,x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                printf("%c",x);
        }
        else
        {
            while(top!=-1 && priority(stack[top])>=priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}