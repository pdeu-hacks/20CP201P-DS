#include <stdio.h>
#include <stdbool.h>

int main() {
    int MAX;
    printf("Enter the value of MAX: ");
    scanf("%d", &MAX);
    if (MAX < 1) {
        printf("MAX must be greater than or equal to 1.\n");
     return 1;
}

int hashTable[2 * MAX + 1];

for (int i = 0; i < 2 * MAX + 1; i++) {
    hashTable[i] = 0;
}
int n = 2 * MAX - 1;
int arr[n];

int index = 0;
for (int i = -MAX; i <= MAX; i++) {
    if (i != 0) {
        arr[index] = i;
index++; }
}

for (int i = 0; i < n; i++) {
    int num = arr[i];
    int index = (num < 0) ? MAX - num : num;
    hashTable[index] = 1;
 
}
    int num;
    printf("Enter the number to search for: ");
    scanf("%d", &num);
    if (num >= -MAX && num <= MAX) {
        // Search for the number in the hash table
        int index = (num < 0) ? MAX - num : num;
        bool isPresent = hashTable[index] == 1;
        if (isPresent) {
            printf("%d is present in the array.\n", num);
        } else {
            printf("%d is not present in the array.\n", num);
}
} else {
        printf("Number is out of range.\n");
    }
return 0; 

}