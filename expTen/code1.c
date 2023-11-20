#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

bool isSubset(int A[], int n, int B[], int m) {
    
    int hashTable[MAX] = {0};
    
    for (int i = 0; i < n; i++) {
        hashTable[A[i]] = 1;
 }
   
    for (int i = 0; i < m; i++) {
        if (hashTable[B[i]] == 0) {
            return false; 
        }
}
    return true; 
}

int main() {
    int n, m;
    printf("Enter the number of elements in array A: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of array A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); 
    }
    printf("Enter the number of elements in array B: ");
    scanf("%d", &m);
    int B[m];
    printf("Enter the elements of array B:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    if (isSubset(A, n, B, m)) {
        printf("Array B is a subset of array A.\n");
    } else {
        printf("Array B is not a subset of array A.\n");
    }

    return 0; 
}