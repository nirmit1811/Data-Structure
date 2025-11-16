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
void BFS(struct Node *graph, int start)
{
    int visited[100]={0};
    int queue[100];
    int front=0,rear=0;
    queue[rear++]=start;
    visited[start]=1;
    printf("\nBFS Traversal starting from %d: ", start);
    while (front<rear)
    {
        int current=queue[front++];
        printf("%d ", current);
        struct Node *ptr=graph;
        while (ptr!=NULL && ptr->data!=current)
            ptr=ptr->node;
        struct Edge *e=ptr->edge;
        while (e!=NULL)
        {
            if (!visited[e->data])
            {
                visited[e->data] = 1;
                queue[rear++] = e->data;
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
        e = e->edge;
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
    struct Node *graph=NULL;
    graph=createNode(graph,1);
    createNode(graph,2);
    createNode(graph,3);
    createNode(graph,4);
    createNode(graph,5);
    createNode(graph,6);
    createEdge(graph,1,2);
    createEdge(graph,1,3);
    createEdge(graph,2,4);
    createEdge(graph,2,5);
    createEdge(graph,3,6);
    createEdge(graph,5,6);
    printGraph(graph);
    int start;
    printf("\nEnter starting node for BFS & DFS: ");
    scanf("%d",&start);
    DFS(graph,start);
    BFS(graph,start);
    return 0;
}
