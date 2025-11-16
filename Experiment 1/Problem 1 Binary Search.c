#include<stdio.h>

int main()
{
    printf("Binary Search\n");
    int n,ele,i,flag=0;
    printf("Enter length of array:-");
    scanf("%d",&n);
    int a[n],mid,lb=0,ub=n-1;
    for (i=0;i<n;i++)
    {
        printf("Enter element:-");
        scanf("%d",&a[i]);
    }
    printf("Enter element to search:-");
    scanf("%d",&ele);
    while (lb<=ub)
    {
        mid=(lb+ub)/2;
        printf("\n%d\n",mid);
        if (a[mid]==ele)
        {
            flag=1;
            break;
        }
        else if (a[mid]<ele)
            lb=mid+1;
        else
            ub=mid-1;
    }
    if (flag==1)
        printf("Element found at %d",mid+1);
    else
        printf("Element not found");
    return 0;
}
