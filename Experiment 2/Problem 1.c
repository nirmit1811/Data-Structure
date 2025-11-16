#include<stdio.h>
#include<string.h>
struct Student
{
    char name[20];
    int roll_no;
    char address[100];
};
int main()
{
    struct Student s1;
    strcpy(s1.name,"Nirmit Jani");
    s1.roll_no=86;
    strcpy(s1.address,"M 41/244, Pragatinagar");
    printf("Student Details:-\n");
    printf("\nName:-%s\n",s1.name);
    printf("Roll Number:-%d\n",s1.roll_no);
    printf("Address:-%s\n",s1.address);
    return 0;
}

/*3$@%#
NirmitJ5!068*/
