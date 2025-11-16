#include<stdio.h>
struct Queue
{
    int size,front,rear;
    int *array;
};
struct Queue *createQueue(int size)
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->array=(int *)malloc(sizeof(int)*size);
    return q;
}
int isFull(struct Queue *q)
{
    if ((q->front==0 && q->rear==q->size-1) || (q->front==q->rear+1))
        return 1;
    else
        return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->front==-1)
        return 1;
    else
        return 0;
}
void enqueue(struct Queue *q,int item)
{
    if (isFull(q))
    {
        printf("\nQueue is Full\n");
        return;
    }
    else
    {
        if (q->front==-1)
        {
            q->front=0;
            q->rear=0;
        }
        else if (q->rear==q->size-1)
            q->rear=0;
        else
            q->rear+=1;
        q->array[q->rear]=item;
        printf("\nElement Entered\n");
    }
}
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        printf("\nElement %d deleted\n",q->array[q->front]);
        if (q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else if (q->front==q->size-1)
            q->front=0;
        else
            q->front+=1;
    }
}
void printfr(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nFront element:- %d",q->array[q->front]);
        printf("\nRear element:- %d\n",q->array[q->rear]);
    }
}
int main()
{
    int size,item,c;
    printf("Enter size of Queue:-");
    scanf("%d",&size);
    struct Queue *q=createQueue(size);
    while (1)
    {
        printf("\nOperations:-\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Print Front and Rear elements\n");
        printf("4.Exit\n");
        printf("Enter your choice:-");
        scanf("%d",&c);
        if (c==1)
        {
            printf("\nEnter element to enter:-");
            scanf("%d",&item);
            enqueue(q,item);
        }
        else if (c==2)
            dequeue(q);
        else if (c==3)
            printfr(q);
        else if (c==4)
            break;
        else
            printf("\nWrong input\n");
    }
    return 0;
}
