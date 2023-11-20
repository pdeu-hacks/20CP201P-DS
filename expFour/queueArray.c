#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
        }
        queue->items[queue->rear] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

int dequeue(struct Queue *queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        data = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
        }
        return data;
    }
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Queue elements: ");
        while (i != queue->rear) {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE; // Circular increment
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    struct Queue linearQueue;
    struct Queue circularQueue;

    initializeQueue(&linearQueue);
    initializeQueue(&circularQueue);


    printf("Linear Queue:\n");
    enqueue(&linearQueue, 1);
    enqueue(&linearQueue, 2);
    enqueue(&linearQueue, 3);
    display(&linearQueue);
    printf("Dequeued: %d\n", dequeue(&linearQueue));
    display(&linearQueue);


    printf("\nCircular Queue:\n");
    enqueue(&circularQueue, 4);
    enqueue(&circularQueue, 5);
    enqueue(&circularQueue, 6);
    display(&circularQueue);
    printf("Dequeued: %d\n", dequeue(&circularQueue));
    display(&circularQueue);

    return 0;
}