#include <stdio.h>

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
        printf("%d, ", inputArray[i]);
    }
    printf("\n");

    for (int i = 0; i < numElements; i++) {
        for (int j = i + 1; j < numElements; j++) {
            if (inputArray[i] > inputArray[j]) {
                int temp = inputArray[j];
                inputArray[j] = inputArray[i];
                inputArray[i] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d, ", inputArray[i]);
    }
    printf("\n");

    printf("Largest element: %d\n", inputArray[numElements - 1]);
    printf("Second largest element: %d\n", inputArray[numElements - 2]);
    printf("Smallest element: %d\n", inputArray[0]);
    printf("Second smallest element: %d\n", inputArray[1]);

    return 0;
}