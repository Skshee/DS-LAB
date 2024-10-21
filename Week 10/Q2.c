#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a node in the binary tree
struct Node* insert(struct Node* root, int value) {
    // Base case: If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root node
    return root;
}

// Function to print the tree structure
void printTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Process left child
    printTree(root->left, space);
}

// Menu-driven program
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Print the tree structure\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a node
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                // Print the tree structure
                printf("Tree structure:\n");
                printTree(root, 0);
                printf("\n");
                break;

            case 3:
                // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
