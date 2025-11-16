#include<stdio.h>

int main()
{
    printf("Linear Search\n");
    int n,ele,i,flag=0;
    printf("Enter length of array:-");
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        printf("Enter element:-");
        scanf("%d",&a[i]);
    }
    printf("Enter element to search:-");
    scanf("%d",&ele);
    for (i=0;i<n;i++)
    {
        if (ele==a[i])
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        printf("Element found at %d",i+1);
    else
        printf("Element not found");
    return 0;
}
