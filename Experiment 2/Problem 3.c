#include <stdio.h>

struct Organization
{
    char orgName[30];
    int orgID;
    struct Employee
    {
        int empID;
        int empSal;
        char empName[30];
    } e[2];
};
int main()
{
    struct Organization o[2];
    int i,j;
    for (i=0;i<2;i++)
    {
        printf("\nEnter Organization %d details:-\n",i+1);
        printf("Name:-");
        fgets(o[i].orgName,sizeof(o[i].orgName),stdin);
        printf("ID:-");
        scanf("%d", &o[i].orgID);
        for (j=0;j<2;j++)
        {
            printf("Enter employee %d details:-\n",j+1);
            printf("ID:-");
            scanf("%d",&o[i].e[j].empID);
            printf("Salary:-");
            scanf("%d",&o[i].e[j].empSal);
            printf("Name:-");
            getchar();
            fgets(o[i].e[j].empName,sizeof(o[i].e[j].empName),stdin);
        }
    }
    for (i=0;i<2;i++)
    {
        printf("\nOrganization %d details:-\n", i + 1);
        printf("Name:- %s",o[i].orgName);
        printf("ID:- %d\n",o[i].orgID);
        for (j=0;j<2;j++)
        {
            printf("Employee %d details:-\n", j+1);
            printf("ID:- %d\n", o[i].e[j].empID);
            printf("Salary:- %d\n", o[i].e[j].empSal);
            printf("Name:- %s", o[i].e[j].empName);
        }
    }
    return 0;
}
