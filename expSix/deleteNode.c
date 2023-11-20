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

void deleteFromBeginning(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    if (list->head->next == NULL) {
        // Single node in the list
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

void deleteFromMiddle(LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from middle.\n");
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
        return;
    }

    if (prev == NULL) {
        // Node to delete is the head
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    LinkedList list;
    list.head = NULL;

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append a node\n");
        printf("2. Delete from the beginning\n");
        printf("3. Delete from the end\n");
        printf("4. Delete from the middle\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&list, data);
                break;
            case 2:
                deleteFromBeginning(&list);
                printf("Deleted node from the beginning.\n");
                break;
            case 3:
                deleteFromEnd(&list);
                printf("Deleted node from the end.\n");
                break;
            case 4:
                printf("Enter data of the node to delete from the middle: ");
                scanf("%d", &data);
                deleteFromMiddle(&list, data);
                break;
            case 5:
                printf("List:\n");
                display(list);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}