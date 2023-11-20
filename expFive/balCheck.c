#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


struct Stack {
    char items[MAX_SIZE];
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


void push(struct Stack *stack, char ch) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack->items[++stack->top] = ch;
    }
}


char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character
    } else {
        return stack->items[stack->top--];
    }
}

bool areParenthesesBalanced(char *expression) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return false;
            } else {
                char topChar = pop(&stack);
                if ((ch == ')' && topChar != '(') ||
                    (ch == '}' && topChar != '{') ||
                    (ch == ']' && topChar != '[')) {
                    return false; 
                }
            }
        }
    }

    
    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}