#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char x)
{
stack[++top]=x;
}
char pop()
{
return stack[top--];
}
int priority(char x)
{
if(x=='^')
return 3;
if(x=='*'||x=='/')
return 2;
if(x=='+'||x=='-')
return 1;
return 0;
}
void infixToPostfix(char infix[])
{
char postfix[MAX];
int i,k=0;
char x;
for(i=0;infix[i]!='\0';i++)
{
if(isalnum(infix[i]))
postfix[k++]=infix[i];
else if(infix[i]=='(')
push(infix[i]);
else if(infix[i]==')')
{
while(top!=-1&&stack[top]!='(')
postfix[k++]=pop();
pop();
}
else
{
while(top!=-1&&stack[top]!='('&&priority(stack[top])>=priority(infix[i]))
postfix[k++]=pop();
push(infix[i]);
}
}
while(top!=-1)
postfix[k++]=pop();
postfix[k]='\0';
printf("Postfix:%s",postfix);
}
int main()
{
push('A');
push('B');
printf("%c\n",pop());
printf("%c\n",pop());
return 0;
}
