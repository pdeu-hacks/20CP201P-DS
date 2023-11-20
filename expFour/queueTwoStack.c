#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack->items[++stack->top] = data;
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

struct Queue {
    struct Stack stack1; 
    struct Stack stack2; 
};

void initializeQueue(struct Queue *queue) {
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(&queue->stack1)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
        push(&queue->stack1, data);
        while (!isEmpty(&queue->stack2)) {
            push(&queue->stack1, pop(&queue->stack2));
        }
    }
}

int dequeue(struct Queue *queue) {
    if (isEmpty(&queue->stack1)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        return pop(&queue->stack1);
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}