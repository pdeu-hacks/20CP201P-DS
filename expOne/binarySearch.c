#include <stdio.h>

int main() {

    int targetValue,low = 0,found = 0,arraySize=10;
    int dataArray[10];
    int high = sizeof(dataArray) / sizeof(targetValue); 

    for(int i = 0; i<arraySize;i++){
        printf("Enter a number : ");
        scanf("%d", &dataArray[i]);
    }

    printf("Enter an integer to find: ");
    scanf("%d", &targetValue);

    while (low <= high) {
        int mid = low + ((high - low) / 2);
        
        if (dataArray[mid] == targetValue) {
            printf("Integer found at position %d\n", mid);
            found = 1;
            break;
        } else if (targetValue < dataArray[mid]) {
            high = mid - 1;
        } else if (targetValue > dataArray[mid]) {
            low = mid + 1;
        }
    }

    if (found == 0) {
        printf("Search FAILED!\n");
    }

    return 0;
}