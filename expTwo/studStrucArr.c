#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char studName[20];
    char studAdrs[40];
};

typedef struct Student studType;

int main() {
    studType studArr[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Name: ");
        scanf("%s", studArr[i].studName);

        printf("Enter Roll No: ");
        scanf("%d", &studArr[i].rollNo);
       
        printf("Enter Address: ");
        scanf("%s", studArr[i].studAdrs);
    }

    for (int j = 0; j < 5; j++) {
        printf("%d\n", studArr[j].rollNo);
        printf("%s\n", studArr[j].studName);
        printf("%s\n", studArr[j].studAdrs);
        printf("-------\n");
    }

    return 0;
}