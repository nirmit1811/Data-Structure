#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size,top;
    int *array;
};
struct Stack *createStack(int size)
{
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    s->size=size;
    s->top=-1;
    s->array=(int *)malloc(sizeof(int)*size);
    return s;
}
int isEmpty(struct Stack *s)
{
    if (s->top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct Stack *s)
{
    if (s->top==s->size-1)
        return 1;
    else
        return 0;
}
void push(struct Stack *s,int item)
{
    if (isFull(s))
    {
        printf("\nStack is Full\n");
        return;
    }
    else
    {
        s->top=s->top+1;
        s->array[s->top]=item;
        printf("\nElement pushed\n");
    }
}
void pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Empty\n");
        return;
    }
    else
    {
        printf("\nElement %d popped\n",s->array[s->top]);
        s->top=s->top-1;
    }
}
void print_top(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty\n");
        return;
    }
    else
        printf("\nElement at top is %d\n",s->array[s->top]);
}
int main()
{
    int size,c,item;
    printf("Enter the size of stack:-");
    scanf("%d",&size);
    struct Stack *s=createStack(size);
    while (1)
    {
        printf("\nOperations:-\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print top element\n");
        printf("4.Exit\n");
        printf("Enter your choice:-");
        scanf("%d",&c);
        if (c==1)
        {
            printf("\nEnter element to enter:-");
            scanf("%d",&item);
            push(s,item);
        }
        else if (c==2)
            pop(s);
        else if (c==3)
            print_top(s);
        else if (c==4)
            break;
        else
            printf("\nWrong input\n");
    }
    return 0;
}
