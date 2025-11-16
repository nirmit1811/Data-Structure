#include<stdio.h>
#include<stdlib.h>
struct Edge
{
    int data;
    struct Edge *edge;
};
struct Node
{
    int data;
    struct Node *node;
    struct Edge *edge;
};
struct Node *createNode(struct Node *graph,int data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->node=NULL;
    new_node->edge=NULL;
    struct Node *ptr=graph;
    if (graph==NULL)
    {
        printf("Node %d entered\n",data);
        return new_node;
    }
    else
    {
        while (ptr->node!=NULL)
            ptr=ptr->node;
        ptr->node=new_node;
        printf("Node %d entered\n",data);
    }
}
void createEdge(struct Node *graph,int source_data,int destination_data)
{
    struct Edge *new_edge=(struct Edge *)malloc(sizeof(struct Edge));
    new_edge->data=destination_data;
    new_edge->edge=NULL;
    struct Node *ptr=graph;
    while (ptr->data!=source_data)
        ptr=ptr->node;
    if (ptr->edge==NULL)
        ptr->edge=new_edge;
    else
    {
        struct Edge *ptr2=ptr->edge;
        while (ptr2->edge!=NULL)
            ptr2=ptr2->edge;
        ptr2->edge=new_edge;
    }
}
struct QNode
{
    int data;
    struct QNode *next;
};
struct Queue
{
    struct QNode *front, *rear;
};
struct Queue *createQueue()
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->front=q->rear=NULL;
    return q;
}
void printGraph(struct Node *ptr)
{
    printf("Node Edge\n");
    printf("List List\n");
    while (ptr!=NULL)
    {
        printf("%d",ptr->data);
        if (ptr->edge!=NULL)
        {
            struct Edge *ptr2=ptr->edge;
            while (ptr2!=NULL)
            {
                printf("--->%d",ptr2->data);
                ptr2=ptr2->edge;
            }
        }
        printf("--->NULL\n");
        ptr=ptr->node;
    }
}
void enqueue(struct Queue *q,int data)
{
    struct QNode *newNode=(struct QNode *)malloc(sizeof(struct QNode));
    newNode->data=data;
    newNode->next=NULL;
    if (q->front==NULL)
    {
        q->front=q->rear=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}
int dequeue(struct Queue *q)
{
    if (q->front==NULL)
        return NULL;
    struct QNode *temp=q->front;
    int info=temp->data;
    q->front=q->front->next;
    if (q->front==NULL)
        q->rear==NULL;
    free(temp);
    return info;
}
int InVisit(int info,int visited[100],int i)
{
    for (int j=0;j<=i;j++)
    {
        if (visited[j]==info)
            return 0;
    }
    return 1;
}
void BFS(struct Node *graph, int start)
{
    int visited[100],i=0;
    struct Queue *q=createQueue();
    enqueue(q,start);
    visited[i++]=start;
    printf("\nBFS Traversal starting from %d: ",start);
    while (q->front!=NULL)
    {
        int current=dequeue(q);
        printf("%d ",current);
        struct Node *ptr=graph;
        while (ptr!=NULL && ptr->data!=current)
            ptr=ptr->node;
        struct Edge *e=ptr->edge;
        while (e!=NULL)
        {
            if (InVisit(e->data,visited,i))
            {
                visited[i++]=e->data;
                enqueue(q,e->data);
            }
            e=e->edge;
        }
    }
    printf("\n");
}
void DFSUtil(struct Node *graph, int data, int visited[])
{
    visited[data] = 1;
    printf("%d ", data);
    struct Node *ptr = graph;
    while (ptr != NULL && ptr->data != data)
        ptr = ptr->node;
    struct Edge *e = ptr->edge;
    while (e != NULL)
    {
        if (!visited[e->data])
            DFSUtil(graph, e->data, visited);
        e=e->edge;
    }
}
void DFS(struct Node *graph, int start)
{
    int visited[100] = {0};
    printf("\nDFS Traversal starting from %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
}
int main()
{
    int n,e,sd,dd;
    int vertex[10];
    struct Node *graph=NULL;
    printf("Enter no. of Nodes:-");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter name of node %d:-",i+1);
        scanf("%d",&vertex[i]);
        if (i==0)
            graph=createNode(graph,vertex[i]);
        else
            createNode(graph,vertex[i]);
    }
    printf("\nEnter no of edges:-");
    scanf("%d",&e);
    for (int i=0;i<e;i++)
    {
        printf("Enter source and destination for %d edge:-",i+1);
        scanf("%d %d",&sd,&dd);
        createEdge(graph,sd,dd);
    }
    printGraph(graph);
    int start;
    printf("\nEnter starting node for BFS & DFS: ");
    scanf("%d",&start);
    DFS(graph,start);
    BFS(graph,start);
    return 0;
}
