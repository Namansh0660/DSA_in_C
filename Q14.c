//Prefix Evaluation using stack
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define size 50
int stack[size];
int top=-1;
void push(int ele)
{
    stack[++top]=ele;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char postfix[50],c;
    int i,op1,op2;
    printf("Enter expression \n");
    scanf("%s",postfix);
    i=strlen(postfix)-1;
    while(i!=-1) {   
        c=postfix[i--];
        if(isdigit(c))
            push(c-'0');
        else {
            op1=pop();
            op2=pop();
            switch(c) {
                case '+':push (op1+op2);
                         break;
                case '-':push (op1-op2);
                         break;
                case '*':push (op1*op2);
                         break;
                case '/':push (op1/op2);
                         break;
            }
        }
    }
    printf("The result of expression is : %d",stack[top]);
    return 0;
}