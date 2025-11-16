#include<stdio.h>

int main()
{
    printf("Selection Sort\n");
    int n,i,j,min,temp;
    printf("Enter length of array:-");
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        printf("Enter element:-");
        scanf("%d",&a[i]);
    }
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
            if (a[j]<a[min])
                min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("Sorted Array:- ");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
