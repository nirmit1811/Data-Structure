#include<stdio.h>

struct Student
{
    char name[20];
    int roll_no;
    char address[100];
};
int main()
{
    struct Student s[5];
    int i;
    printf("Enter Student details:-\n");
    for (i=0;i<5;i++)
    {
        printf("\nEnter Student %d details:-\n",i+1);
        printf("Enter Name:-");
        fgets(s[i].name,sizeof(s[i].name),stdin);
        printf("Enter Roll number:-");
        scanf("%d",&s[i].roll_no);
        printf("Enter Address:-");
        getchar();
        fgets(s[i].address,sizeof(s[i].address),stdin);
    }
    printf("\nStudent Details:-\n");
    for (i=0;i<5;i++)
    {
        printf("\nStudent %d details:-\n",i+1);
        printf("Name:- %s",s[i].name);
        printf("Roll Number:- %d\n",s[i].roll_no);
        printf("Address:- %s\n",s[i].address);
    }
    return 0;
}
