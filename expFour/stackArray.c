#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1; // You can choose an appropriate value to indicate underflow
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // You can choose an appropriate value to indicate an empty stack
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    return 0;
}