#include <stdio.h>
#include <string.h>

struct Employee{
    int empId;
    char empName[20];
    int empSalary;
};

struct Organization{
    int orgId;
    struct Employee empArr[2];
    
};

typedef struct Organization orgType;

int main(){
    orgType orgArr[2];

    for(int i=0;i<2;i++){
        printf("%s","Organization ID : ");
        scanf("%d",&orgArr[i].orgId);
        for(int j=0;j<2;j++){
            printf("%s","Employee ID : ");
            scanf("%d",&orgArr[i].empArr[j].empId);
            printf("%s","Name : ");
            scanf("%s",orgArr[i].empArr[j].empName);
            printf("%s","Salary : ");
            scanf("%d",&orgArr[i].empArr[j].empSalary);
        }
    };

    printf("\n Output \n");
    for(int i=0;i<2;i++){
        printf("%s %d \n","Organization",orgArr[i].orgId);
        for(int j=0;j<2;j++){
            printf("%s %d \n","Employee ID",orgArr[i].empArr[j].empId);
            printf("%s %s \n","Name",orgArr[i].empArr[j].empName);
            printf("%s %d \n","Salary",orgArr[i].empArr[j].empSalary);
            printf("\n");
        }
        printf("\n");
    };


    return 0; 
}