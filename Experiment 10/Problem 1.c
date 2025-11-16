#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node
{
    int data;
    struct Node* next;
};
struct Node *hashTable[SIZE];
struct Node *createNode(int value)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
int hashFunction(int key)
{
    return key%SIZE;
}
void insert(int value)
{
    int index=hashFunction(value);
    struct Node *newNode=createNode(value);
    if (hashTable[index]==NULL)
    {
        hashTable[index]=newNode;
    }
    else
    {
        newNode->next=hashTable[index];
        hashTable[index]=newNode;
    }
}
void printHashTable()
{
    for (int i=0;i<SIZE;i++)
    {
        printf("%d --> ",i);
        struct Node *temp=hashTable[i];
        while (temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
   for (int i=0;i<SIZE;i++)
        hashTable[i]=NULL;
    int n,value;
    printf("Enter number of values to insert:-");
    scanf("%d",&n);
    printf("Enter %d values:-\n",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&value);
        insert(value);
    }
    printf("\nHash Table:\n");
    printHashTable();
    return 0;
}
