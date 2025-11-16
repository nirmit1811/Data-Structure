#include<stdio.h>

struct Student
{
    char name[20];
    int roll_no;
    int marks;
};
int main()
{
    struct Student s1;
    struct Student *ptr=&s1;
    printf("Enter details:-\n");
    printf("Enter Name:-");
    fgets(ptr->name,sizeof(ptr->name),stdin);
    printf("Enter Roll Number:-");
    scanf("%d",&ptr->roll_no);
    printf("Enter Marks:-");
    scanf("%d",&ptr->marks);
    printf("\nDetails of student:-\n");
    printf("Name:- %s",ptr->name);
    printf("Roll Number:- %d\n",ptr->roll_no);
    printf("Marks:- %d\n",ptr->marks);
    return 0;
}
