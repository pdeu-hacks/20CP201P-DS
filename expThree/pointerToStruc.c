#include <stdio.h>

struct person
{
   int prsnAge;
   float prsnWght;
};

int main()
{
    struct person *personPtr, personOne;
    personPtr = &personOne;   

    printf("Enter age: ");
    scanf("%d", &personPtr->prsnAge);

    printf("Enter weight: ");
    scanf("%f", &personPtr->prsnWght);

    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->prsnAge);
    printf("weight: %f", personPtr->prsnWght);
    printf("\n");
    return 0;
}