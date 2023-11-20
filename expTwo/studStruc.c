#include <stdio.h>
#include <string.h>

struct Student{
    int rollNo;
    char studName[20];
    char studAdrs[40];
};

typedef struct Student stud;

int main(){
    stud a;
    a.rollNo=21;
    strcpy(a.studName,"Mahesh");
    strcpy(a.studAdrs,"Delhi");

    printf("%d \n",a.rollNo);
    printf("%s \n",a.studName);
    printf("%s \n",a.studAdrs);

    return 0;
}