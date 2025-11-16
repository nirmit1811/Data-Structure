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
        if (isdigit(exp[i]))
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
int evaluatpostfix(char postfix[])
{
    char stack[50];
    int top=-1,i=0,j,A,B,product;
    while (postfix[i]!='\0')
    {
        if (isdigit(postfix[i]))
        {
            top+=1;
            stack[top]=postfix[i]-'0';
        }
        else
        {
            A=stack[top];
            B=stack[top-1];
            top-=1;
            switch (postfix[i])
            {
            case ('+'):
                stack[top]=(B+A);
                break;
            case ('-'):
                stack[top]=(B-A);
                break;
            case ('*'):
                stack[top]=(B*A);
                break;
            case ('/'):
                stack[top]=(B/A);
                break;
            case ('^'):
                product=1;
                for (int j=0;j<A;j++)
                    product*=B;
                stack[top]=product;
                break;
            }
        }
        i+=1;
    }
    return stack[top];
}
int main()
{
    char exp[50],postfix[50];
    printf("Enter infix:-");
    scanf("%s",exp);
    infixtopostfix(exp,postfix);
    printf("Postfix Form:- %s\n",postfix);
    int result=evaluatpostfix(postfix);
    printf("Result:- %d",result);
    return 0;
}
