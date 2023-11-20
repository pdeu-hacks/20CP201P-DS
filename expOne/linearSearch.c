#include <stdio.h>

int main() {

    int searchValue,arraySize=10,found=0;
    int dataArray[10];

    for(int i = 0; i<arraySize;i++){
        printf("Enter a number : ");
        scanf("%d", &dataArray[i]);
    }

    printf("Enter a number to find: ");
    scanf("%d", &searchValue);

    for (int j = 0; j < arraySize; j++) {
        if (dataArray[j] == searchValue) {
            printf("Value found at position %d\n", j);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Search FAILED!\n");
    }

    return 0;
}