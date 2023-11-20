#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

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

void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void display(LinkedList list) {
    Node* current = list.head;
    while (current != NULL) {
        printf("%d => ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertAtFront(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
}

void insertAfter(LinkedList* list, int prevData, int newData) {
    Node* current = list->head;

    while (current != NULL && current->data != prevData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found\n", prevData);
        return;
    }

    Node* newNode = createNode(newData);
    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    LinkedList list;
    list.head = NULL;

    int choice, data,prevData;
    Node* prevNode;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the front\n");
        printf("3. Insert after a given node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                append(&list, data);
                break;
            case 2:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertAtFront(&list, data);
                break;
            case 3:
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &prevData);
                printf("Enter data to insert after the node: ");
                scanf("%d", &data);
                insertAfter(&list, prevData, data);
    break;
            case 4:
                printf("List:\n");
                display(list);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}