#include<stdio.h>

void swap(int *,int *);
int main()
{

    int numOne,numTwo;
    printf("Input 1st number : ");
    scanf("%d",&numOne);
    printf("Input 2nd number : ");
    scanf("%d",&numTwo);	

    printf("Before swapping: n1 = %d, n2 = %d ",numOne,numTwo);
    swap(&numOne,&numTwo);

    printf("\nAfter swapping: n1 = %d, n2 = %d \n\n",numOne,numTwo);
    return 0;
}

void swap(int *swapVarOne,int *swapVarTwo)
{
    int tmpVar;
    tmpVar = *swapVarOne;
    *swapVarOne=*swapVarTwo;
    *swapVarTwo=tmpVar;
}