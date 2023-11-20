#include <stdio.h>

void bubbleSort(int array[], int length) {
    int temp;
    int swapped;

    for (int i = 0; i < length - 1; i++) {
        swapped = 0; // Flag to check if any swaps were made in this pass
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1; // Set the flag to indicate a swap
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == 0)
            break;
    }
}

int main() {
    int inputArray[10]; // Declare an array of size 10
    int arrayLength = 10;   // Size of the array

    printf("Enter 10 integers:\n");
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d", &inputArray[i]); // Read input from the user
    }

    printf("Original array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", inputArray[i]);
    }

    bubbleSort(inputArray, arrayLength);

    printf("\nSorted array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}