#include<stdio.h>

int main()
{
    int a=10,b=20,c=30,i;
    int *arr[3]={&a,&b,&c}; //array of pointers
    for (i=0;i<3;i++)
        printf("%d\n",*arr[i]);
    printf("\n");
    int ar[3]={40,50,60};
    int (*p)[3]=&ar; //pointer to array
    for (i=0;i<3;i++)
        printf("%d\n",(*p)[i]);
}
