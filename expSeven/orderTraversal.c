#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void recursivePreorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}

void recursiveInorder(struct TreeNode* root) {
    if (root != NULL) {
        recursiveInorder(root->left);
        printf("%d ", root->data);
        recursiveInorder(root->right);
    }
}

void recursivePostorder(struct TreeNode* root) {
    if (root != NULL) {
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        printf("%d ", root->data);
    }
}

void iterativePreorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    struct TreeNode* current;
    struct TreeNode* stack[100]; // Assuming a maximum of 100 nodes
    
    int top = -1;
    stack[++top] = root;
    
    while (top >= 0) {
        current = stack[top--];
        printf("%d ", current->data);
        
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

void iterativeInorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    struct TreeNode* current;
    struct TreeNode* stack[100]; // Assuming a maximum of 100 nodes
    
    int top = -1;
    current = root;
    
    while (top >= 0 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void iterativePostorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    struct TreeNode* current;
    struct TreeNode* stack[100]; // Assuming a maximum of 100 nodes
    struct TreeNode* prev = NULL;
    
    int top = -1;
    
    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        
        while (root == NULL && top != -1) {
            root = stack[top];
            if (root->right == NULL || root->right == prev) {
                printf("%d ", root->data);
                top--;
                prev = root;
                root = NULL;
            } else {
                root = root->right;
            }
        }
    } while (top != -1);
}

int main() {
    struct TreeNode* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Recursive Preorder Traversal: ");
    recursivePreorder(root);
    printf("\n");
    
    printf("Recursive Inorder Traversal: ");
    recursiveInorder(root);
    printf("\n");
    
    printf("Recursive Postorder Traversal: ");
    recursivePostorder(root);
    printf("\n");
    
    printf("Iterative Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");
    
    printf("Iterative Inorder Traversal: ");
    iterativeInorder(root);
    printf("\n");
    
    printf("Iterative Postorder Traversal: ");
    iterativePostorder(root);
    printf("\n");
    
    return 0;
}