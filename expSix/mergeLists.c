#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void insertNode(struct ListNode **head, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct ListNode* mergeSortedLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    if (list1 != NULL) {
        current->next = list1;
    }
    
    if (list2 != NULL) {
        current->next = list2;
    }
    
    return dummy->next;
}

void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d => ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    
    insertNode(&list1, 5);
    insertNode(&list1, 10);
    insertNode(&list1, 15);
    
    insertNode(&list2, 2);
    insertNode(&list2, 3);
    insertNode(&list2, 20);
    
    printf("List 1: ");
    printList(list1);
    
    printf("List 2: ");
    printList(list2);
    
    struct ListNode *mergedList = mergeSortedLists(list1, list2);
    
    printf("Merged List: ");
    printList(mergedList);
    
    return 0;
}