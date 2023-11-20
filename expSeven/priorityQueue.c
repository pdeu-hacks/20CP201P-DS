#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element in the priority queue
struct Element {
    int data;
    int priority;
};

// Structure for the priority queue
struct PriorityQueue {
    struct Element* elements;
    int capacity;
    int size;
};

// Function to create a new priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->elements = (struct Element*)malloc(sizeof(struct Element) * capacity);
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

// Function to swap two elements in the priority queue
void swap(struct Element* a, struct Element* b) {
    struct Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property
void heapify(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->elements[left].priority < pq->elements[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->elements[right].priority < pq->elements[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(&pq->elements[i], &pq->elements[smallest]);
        heapify(pq, smallest);
    }
}

// Function to insert an element with priority into the priority queue
void insert(struct PriorityQueue* pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    }

    int i = pq->size;
    pq->size++;
    pq->elements[i].data = data;
    pq->elements[i].priority = priority;

    while (i > 0 && pq->elements[(i - 1) / 2].priority > pq->elements[i].priority) {
        swap(&pq->elements[i], &pq->elements[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the element with the highest priority
int extractMin(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty. Cannot extract minimum.\n");
        return -1; // Return a sentinel value indicating an error
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->elements[0].data;
    }

    int root = pq->elements[0].data;
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue(10);

    insert(pq, 4, 10);
    insert(pq, 6, 5);
    insert(pq, 2, 20);
    insert(pq, 8, 2);
    insert(pq, 1, 50);

    printf("Priority Queue Elements: ");
    while (!isEmpty(pq)) {
        printf("%d ", extractMin(pq));
    }
    printf("\n");

    free(pq->elements);
    free(pq);
    
    return 0;
}