#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *start=NULL;
struct Node *createNode(int item)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    if (new_node==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->info=item;
    new_node->link=NULL;
    return new_node;
}
struct Node *loc(int pos)
{
    struct Node *ploc=start;
    for (int i=2;i<=pos;i++)
        if (ploc!=NULL)
            ploc=ploc->link;
        else
            break;
    return ploc;
}
void insertAtFront(int item)
{
    struct Node *new_node=createNode(item);
    new_node->link=start;
    start=new_node;
    printf("\nElement %d entered\n",item);
}
void insertAtBetween(int pos,int item)
{
    if (pos<0)
    {
        printf("Invalid Location of Node");
        return;
    }
    else if (pos==0)
    {
        insertAtFront(item);
        return;
    }
    struct Node *ploc=loc(pos);
    if (ploc==NULL)
    {
        printf("Position out of range");
        return;
    }
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->info=item;
    new_node->link=ploc->link;
    ploc->link=new_node;
    printf("\nElement %d entered\n",item);
}
void insertAtEnd(int item)
{
    struct Node *new_node=createNode(item);
    if (start==NULL)
    {
        start=new_node;
    }
    else
    {
        struct Node *ptr=start;
        while (ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=new_node;
    }
    printf("\nElement %d entered\n",item);
}
void deleteAtFront()
{
    if (start==NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    struct Node *temp=start;
    printf("\nElement %d deleted\n",temp->info);
    start=start->link;
    free(temp);
}
void deleteAtPos(int pos)
{
    if (pos<=0)
    {
        printf("Invalid Location of Node");
        return;
    }
    else if (pos==1)
    {
        deleteAtFront();
        return;
    }
    struct Node *ploc=loc(pos-1);
    if (ploc==NULL)
    {
        printf("\nPosition out of range\n");
        return;
    }
    struct Node *temp=ploc->link;
    printf("\nElement %d deleted\n",temp->info);
    ploc->link=temp->link;
    free(temp);
}
void deleteAtEnd()
{
    struct Node *temp=start;
    while (temp->link->link!=NULL)
        temp=temp->link;
    printf("\nElement %d deleted\n",temp->link->info);
    free(temp->link);
    temp->link=NULL;
}
void printll()
{
    struct Node *ptr=start;
    printf("\n");
    while (ptr!=NULL)
    {
        printf("%d -> ",ptr->info);
        ptr=ptr->link;
    }
    printf("NULL\n");
}
int main()
{
    int wc=1,choice,item,pos;
    while(wc)
    {
        printf("\n1.Insert at the Front\n");
        printf("2.Insert after a given Node\n");
        printf("3.Insert at the End\n");
        printf("4.Delete from the Front\n");
        printf("5.Delete from the position\n");
        printf("6.Delete from the End\n");
        printf("7.Display Linked List\n");
        printf("8.Exit\n");
        printf("Choice from above:-");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter element to enter:-");
            scanf("%d",&item);
            insertAtFront(item);
            break;
        case 2:
            printf("\nEnter element to enter:-");
            scanf("%d",&item);
            printf("\nEnter position after which to enter:-");
            scanf("%d",&pos);
            insertAtBetween(pos,item);
            break;
        case 3:
            printf("\nEnter element to enter:-");\
            scanf("%d",&item);
            insertAtEnd(item);
            break;
        case 4:
            deleteAtFront();
            break;
        case 5:
            printf("\nEnter position:-");
            scanf("%d",&pos);
            deleteAtPos(pos);
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printll();
            break;
        case 8:
            wc=0;
            break;
        default:
            printf("\nEnter valid choice\n");
        }
    }
    return 0;
}
