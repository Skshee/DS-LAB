#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    char direction;
    printf("Insert %d as left or right child of %d (l/r)? ", data, root->data);
    scanf(" %c", &direction);
    if (direction == 'l' || direction == 'L')
        root->left = insert(root->left, data);
    else if (direction == 'r' || direction == 'R')
        root->right = insert(root->right, data);
    return root;
}


int areMirrors(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           areMirrors(tree1->left, tree2->right) &&
           areMirrors(tree1->right, tree2->left);
}


int main() {
    struct Node *tree1 = NULL, *tree2 = NULL;
    int n, value;


    printf("Enter the number of nodes for the first tree: ");
    scanf("%d", &n);
    printf("Enter the values for the first tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        if (i == 0)
            tree1 = createNode(value); // Root node
        else
            insert(tree1, value);
    }

    printf("\nEnter the number of nodes for the second tree: ");
    scanf("%d", &n);
    printf("Enter the values for the second tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        if (i == 0)
            tree2 = createNode(value); // Root node
        else
            insert(tree2, value);
    }

    if (areMirrors(tree1, tree2))
        printf("The two trees are mirror images.\n");
    else
        printf("The two trees are not mirror images.\n");

    return 0;
}
