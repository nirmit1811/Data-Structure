#include<stdio.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Queue
{
    struct Node *front;
    struct Node *rear;
};
struct Queue *createQueue()
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->front=q->rear=NULL;
    return q;
}
void enqueue(struct Queue *q,int item)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->info=item;
    newNode->link=NULL;
    if (q->front==NULL)
        q->front=q->rear=newNode;
    else
    {
        q->rear->link=newNode;
        q->rear=newNode;
    }
    printf("\n%d enqueued to queue\n",item);
}
void dequeue(struct Queue *q)
{
    if (q->front==NULL)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    struct Node *temp=q->front;
    q->front=q->front->link;
    if (q->front==NULL)
        q->rear==NULL;
    printf("\n%d dequeued from queue\n",temp->info);
    free(temp);
}
void printfr(struct Queue *q)
{
    if (q->front==NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nFront element:- %d",q->front->info);
        printf("\nRear element:- %d\n",q->rear->info);
    }
}
int main()
{
    struct Queue *q=createQueue();
    int c,item;
    while (1)
    {
        printf("\nOperations:-\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Print front and rear elements\n");
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
            printf("\nWrong Choice\n");
    }
    return 0;
}
