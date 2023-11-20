#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        char value = stack->data[stack->top];
        stack->top--;
        return value;
    }
    return '\0'; // Return a sentinel value for empty stack
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0; // Default precedence for other characters
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack operatorStack;
    initialize(&operatorStack);
    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (current >= 'a' && current <= 'z') {
            postfix[postfixIndex++] = current;
        } else if (current == '(') {
            push(&operatorStack, current);
        } else if (current == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the '('
        } else {
            while (!isEmpty(&operatorStack) && precedence(current) <= precedence(operatorStack.data[operatorStack.top])) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, current);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}