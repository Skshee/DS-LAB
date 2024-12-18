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


int areEqual(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           areEqual(tree1->left, tree2->left) && areEqual(tree1->right, tree2->right);
}


int main() {
    struct Node *tree1 = createNode(1);
    tree1->left = createNode(2);
    tree1->right = createNode(3);

    struct Node *tree2 = createNode(1);
    tree2->left = createNode(2);
    tree2->right = createNode(3);

    if (areEqual(tree1, tree2))
        printf("The two trees are equal.\n");
    else
        printf("The two trees are not equal.\n");

    return 0;
}