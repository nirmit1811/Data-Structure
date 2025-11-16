#include<stdio.h>

int main()
{
    printf("Maximum,Minimum and 2nd Max & Min\n");
    int n,i,max,min,max2,min2,temp;
    printf("Enter length of array:-");
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        printf("Enter element:-");
        scanf("%d",&a[i]);
    }
    if (a[0]>a[1])
    {
        max=a[0];
        max2=a[1];
        min=a[1];
        min2=a[0];
    }
    else
    {
        max=a[1];
        max2=a[0];
        min=a[0];
        min2=a[1];
    }
    for (i=2;i<n;i++)
    {
        if (a[i]>max2)
        {
            max2=a[i];
            if (max2>max)
            {
                temp=max;
                max=max2;
                max2=temp;
            }
        }
        if (a[i]<min2)
        {
            min2=a[i];
            if (min2<min)
            {
                temp=min;
                min=min2;
                min2=temp;
            }
        }
    }
    printf("Maximum:-%d\n2nd Maximum:-%d\n2nd Minimum:-%d\nMinimum:-%d",max,max2,min2,min);
    return 0;
}
