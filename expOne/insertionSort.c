#include <stdio.h>

void insertionSort(int array[], int length) {
    int currentIndex, currentElement, j;
    for (currentIndex = 1; currentIndex < length; currentIndex++) {
        currentElement = array[currentIndex];
        j = currentIndex - 1;

        while (j >= 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = currentElement;
    }
}

int main() {
    int arraySize=10,inputArray[10];

    for(int i = 0; i<arraySize;i++){
        printf("Enter a number : ");
        scanf("%d", &inputArray[i]);
    }
    
    int arrayLength = sizeof(inputArray) / sizeof(inputArray[0]);

    printf("Original array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", inputArray[i]);
    }
    
    insertionSort(inputArray, arrayLength);
    
    printf("\nSorted array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", inputArray[i]);
    }
    
    return 0;
}