#include<stdio.h>

int main()
{
    int n1=10,n2=20,temp;
    int *ptr1=&n1,*ptr2=&n2;
    printf("Before Swapping:-\n");
    printf("Numbers:- N1=%d and N2=%d\n",*ptr1,*ptr2);
    printf("Address:- N1=%d and N2=%d\n",ptr1,ptr2);
    temp=ptr1;
    ptr1=ptr2;
    ptr2=temp;
    printf("After Swapping:-\n");
    printf("Numbers:- N1=%d and N2=%d\n",*ptr1,*ptr2);
    printf("Address:- N1=%d and N2=%d\n",ptr1,ptr2);
    return 0;
}
