#include <stdio.h>

int main()
{
    int varOne=36;
    int varTwo=365;
    int varThree=42;
    int varFour=37;
    int varFive=1;
    int *arrOfPntr[5]={&varOne,&varTwo,&varThree,&varFour,&varFive};

    printf("Array of Pointers\n");
    for (int i=0;i<5;i++){
        printf("%p \n",arrOfPntr[i]);
    }

    return 0;
}