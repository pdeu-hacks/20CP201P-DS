#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the height of a binary tree
int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return the maximum of the left and right subtree heights plus 1 (for the current level)
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int main() {
    // Creating a simple binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int height = findHeight(root);

    printf("Height of the binary tree is: %d\n", height);

    return 0;
}