#include<stdio.h>

int main()
{
    printf("Bubble Sort\n");
    int n,i,j,temp,flag=0;
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
        for (j=0;j<n-i;j++)
        {
            printf("g\n");
            if (a[j]>a[j+1])
            {
                flag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if (flag==0)
            break;
    }
    printf("Sorted array:- ");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
