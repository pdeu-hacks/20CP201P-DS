#include <stdio.h>

void selectionSort(int array[], int length) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < length - 1; i++) {
        // Assume the current element is the minimum
        minIndex = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main() {
    int numElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    int inputArray[numElements];

    printf("Enter %d integers:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &inputArray[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", inputArray[i]);
    }

    selectionSort(inputArray, numElements);

    printf("\nSorted array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}