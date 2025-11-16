#include<stdio.h>
#include<ctype.h>
int priority(char c)
{
    if (c=='^')
        return 3;
    else if (c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else
        return 0;
}
void infixtopostfix(char exp[],char postfix[])
{
    char stack[50];
    int top=-1,k=0,i=0;
    while (exp[i]!='\0')
    {
        if (isalpha(exp[i]))
        {
            postfix[k]=exp[i];
            k+=1;
        }
        else if (exp[i]=='(')
        {
            top+=1;
            stack[top]=exp[i];
        }
        else if (exp[i]==')')
        {
            while (stack[top]!='(')
            {
                postfix[k]=stack[top];
                k+=1;
                top-=1;
            }
            top-=1;
        }
        else
        {
            while (top!=-1 && (priority(exp[i])<=priority(stack[top])))
            {
                postfix[k]=stack[top];
                k+=1;
                top-=1;
            }
            top+=1;
            stack[top]=exp[i];
        }
        i+=1;
    }
    while (top!=-1)
    {
        postfix[k]=stack[top];
        k+=1;
        top-=1;
    }
    postfix[k]='\0';
}
int main()
{
    char exp[50],postfix[50];
    printf("Enter infix:-");
    scanf("%s",exp);
    infixtopostfix(exp,postfix);
    printf("Postfix Form:- %s\n",postfix);
    return 0;
}
