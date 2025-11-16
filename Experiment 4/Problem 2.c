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
void push(struct Stack *s,int item)
{
    if (s->top==s->size-1)
    {
        printf("\nStack is Full\n");
        return;
    }
    else
    {
        s->top=s->top+1;
        s->array[s->top]=item;
        printf("\nElement %d is pushed\n",item);
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
void top(struct Stack *s)
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
    int size;
    printf("Enter the size of stack:-");
    scanf("%d",&size);
    struct Stack *s=createStack(size);
    push(s,12);
    push(s,23);
    push(s,34);
    push(s,45);
    top(s);
    pop(s);
    top(s);
    return 0;
}
