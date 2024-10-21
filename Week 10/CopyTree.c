#include <stdio.h>
#include <stdlib.h>

// Node structure for the tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to copy a tree
struct Node* copyTree(struct Node* root) {
    if (root == NULL)
        return NULL;
    
    // Create a new node with the same data as the current node
    struct Node* newNode = createNode(root->data);
    
    // Recursively copy the left and right subtrees
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    
    return newNode;
}

// Function for in-order traversal to display the tree
void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Main function
int main() {
    // Create the original tree
    struct Node *originalTree = createNode(1);
    originalTree->left = createNode(2);
    originalTree->right = createNode(3);
    originalTree->left->left = createNode(4);
    originalTree->left->right = createNode(5);
    originalTree->right->left = createNode(6);
    originalTree->right->right = createNode(7);

    // Copy the tree
    struct Node *copiedTree = copyTree(originalTree);

    // Display the in-order traversal of the original and copied trees
    printf("In-order traversal of the original tree: ");
    inOrderTraversal(originalTree);
    printf("\n");

    printf("In-order traversal of the copied tree: ");
    inOrderTraversal(copiedTree);
    printf("\n");

    return 0;
}
