#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the Deque
void initDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the Deque is empty
bool isEmpty(struct Deque *deque) {
    return (deque->front == -1);
}

// Function to check if the Deque is full
bool isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an item at the front of the Deque
void insertFront(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->arr[deque->front] = item;
}

// Function to insert an item at the rear of the Deque
void insertLast(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->arr[deque->rear] = item;
}

// Function to delete an item from the front of the Deque
void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
}

// Function to delete an item from the rear of the Deque
void deleteLast(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

// Function to get the front item from the Deque
int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot get the front item.\n");
        return -1;
    }
    return deque->arr[deque->front];
}

// Function to get the last item from the Deque
int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot get the rear item.\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    insertFront(&deque, 1);
    insertLast(&deque, 2);
    insertFront(&deque, 3);
    insertLast(&deque, 4);

    printf("Front item: %d\n", getFront(&deque));
    printf("Rear item: %d\n", getRear(&deque));

    deleteFront(&deque);
    deleteLast(&deque);

    printf("Front item after deletion: %d\n", getFront(&deque));
    printf("Rear item after deletion: %d\n", getRear(&deque));

    return 0;
}