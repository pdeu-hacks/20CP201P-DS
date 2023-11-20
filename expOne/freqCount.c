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

    // Count the frequency of each element
    int frequency[numElements];
    for (int i = 0; i < numElements; i++) {
        frequency[i] = -1; // Initialize to -1 to mark as not counted
    }

    for (int i = 0; i < numElements; i++) {
        int count = 1;
        for (int j = i + 1; j < numElements; j++) {
            if (inputArray[i] == inputArray[j]) {
                count++;
                frequency[j] = 0; // Mark as counted
            }
        }
        if (frequency[i] != 0) {
            frequency[i] = count;
        }
    }

    // Print unique elements and their frequencies
    printf("Unique elements and their frequencies:\n");
    for (int i = 0; i < numElements; i++) {
        if (frequency[i] != 0) {
            printf("%d occurs %d times\n", inputArray[i], frequency[i]);
        }
    }

    return 0;
}