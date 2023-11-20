#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* head;
} CircularLinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;  // Make it circular
        return;
    }
    Node* current = list->head;
    while (current->next != list->head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = list->head;  // Make it circular
}

void traverse(CircularLinkedList list) {
    if (list.head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    Node* current = list.head;
    do {
        printf("%d => ", current->data);
        current = current->next;
    } while (current != list.head);
    printf("\n");
}

int main() {
    CircularLinkedList list;
    list.head = NULL;

    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        append(&list, data);
    }

    printf("Circular Linked List:\n");
    traverse(list);

    return 0;
}