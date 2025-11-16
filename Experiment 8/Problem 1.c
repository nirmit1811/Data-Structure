#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};
struct TreeNode *createTreeNode(int data)
{
    struct TreeNode *newNode=(struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct QNode
{
    struct TreeNode *data;
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
void enqueue(struct Queue *q,struct TreeNode *node)
{
    struct QNode *newNode=(struct QNode *)malloc(sizeof(struct QNode));
    newNode->data=node;
    newNode->next=NULL;
    if (q->front==NULL)
    {
        q->front=q->rear=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}
struct TreeNode *dequeue(struct Queue *q)
{
    if (q->front==NULL)
        return NULL;
    struct QNode *temp=q->front;
    struct TreeNode *node=temp->data;
    q->front=q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return node;
}
void levelOrderTraversal(struct TreeNode *root)
{
    if (root==NULL)
        return;
    struct Queue *q=createQueue();
    enqueue(q,root);
    printf("\nLevel Order Traversal: ");
    while (q->front!=NULL)
    {
        struct TreeNode *current=dequeue(q);
        printf("%d ", current->data);
        if (current->left)
            enqueue(q,current->left);
        if (current->right)
            enqueue(q,current->right);
    }
    printf("\n");
}
void inOrder(struct TreeNode *root)
{
    if (root==NULL)
        return;
    printf("In Order:-");
    struct TreeNode *stack[100];
    int top=-1;
    struct TreeNode *current=root;
    while (current!=NULL || top!=-1)
    {
        while (current!=NULL)
        {
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        printf("%d ",current->data);
        current=current->right;
    }
    printf("\n");
}
void preOrder(struct TreeNode *root)
{
    if (root==NULL)
        return;
    printf("Pre Order:-");
    struct TreeNode *stack[100];
    int top=-1;
    stack[++top]=root;
    while (top!=-1)
    {
        struct TreeNode *current=stack[top--];
        printf("%d ",current->data);
        if (current->right)
            stack[++top]=current->right;
        if (current->left)
            stack[++top]=current->left;
    }
    printf("\n");
}
void postOrder(struct TreeNode *root)
{
    if (root==NULL)
        return;
    printf("Post Order:-");
    struct TreeNode *stack1[100],*stack2[100];
    int top1=-1,top2=-1;
    stack1[++top1]=root;
    while (top1!=-1)
    {
        struct TreeNode *temp=stack1[top1--];
        stack2[++top2]=temp;
        if (temp->left)
            stack1[++top1]=temp->left;
        if (temp->right)
            stack1[++top1]=temp->right;
    }
    while (top2!=-1)
        printf("%d ",stack2[top2--]->data);
    printf("\n");
}
int main()
{
    struct TreeNode *root=createTreeNode(1);
    root->left=createTreeNode(2);
    root->right=createTreeNode(3);
    root->left->left=createTreeNode(4);
    root->left->right=createTreeNode(5);
    root->right->right=createTreeNode(6);
    root->left->right->left=createTreeNode(7);
    root->right->right->left=createTreeNode(8);
    /*     1
       2       3
     4   5       6
        7       8*/
    levelOrderTraversal(root);
    inOrder(root);
    preOrder(root);
    postOrder(root);
    return 0;
}
