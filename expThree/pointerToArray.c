#include<stdio.h>

int main()
{
int exArr[5] = { 32, 25, 33, 42, 55 };
int *ptr = exArr;

printf("Pointer to Array\n");

for(int i = 0;i<5;i++){
printf("%d\n", *(ptr+i));
}

return 0;
}