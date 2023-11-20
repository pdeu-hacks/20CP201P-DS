#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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

int evaluatePostfixExpression(char *expression) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            continue;
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error.\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid character in expression: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    if (!isEmpty(&stack)) {
        return pop(&stack);
    } else {
        printf("Empty stack. Invalid postfix expression.\n");
        exit(1);
    }
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    int result = evaluatePostfixExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}