#include<stdio.h>

int main()
{
    printf("Insertion Sort\n");
    int n,key,i,j,k,temp;
    printf("Enter length of array:-");
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        printf("Enter element:-");
        scanf("%d",&a[i]);
    }
    for (i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=key;
    }
    printf("Sorted array:- ");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
