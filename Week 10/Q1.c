#include <stdio.h>
#include <stdlib.h>

// Node structure for the general tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure to store tree nodes for traversals
struct stack {
    struct Node* top;
    struct stack* next;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to push a node onto the stack
void push(struct stack** s, struct Node* n) {
    struct stack* new_Node = (struct stack*)malloc(sizeof(struct stack));
    if (new_Node == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    new_Node->top = n;
    new_Node->next = *s;
    *s = new_Node;
}

// Function to pop a node from the stack
struct Node* pop(struct stack** s) {
    if (*s == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    struct stack* top_ref = *s;
    struct Node* res = top_ref->top;
    *s = top_ref->next;
    free(top_ref);
    return res;
}

// Function for inorder traversal
void inorder(struct Node* root) {
    struct Node* curr = root;
    struct stack* st = NULL;
    while (curr != NULL || st != NULL) {
        while (curr != NULL) {
            push(&st, curr);
            curr = curr->left;
        }
        curr = pop(&st);
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// Function for preorder traversal
void preorder(struct Node* root) {
    struct Node* curr = root;
    struct stack* st = NULL;
    
    if (curr == NULL) return;

    push(&st, curr);
    while (st != NULL) {
        curr = pop(&st);
        printf("%d ", curr->data);

        if (curr->right != NULL)
            push(&st, curr->right);
        if (curr->left != NULL)
            push(&st, curr->left);
    }
    printf("\n");
}

// Function for postorder traversal
void postorder(struct Node* root) {
    struct stack *st1 = NULL, *st2 = NULL;
    struct Node* curr = root;

    if (curr == NULL) return;

    push(&st1, curr);
    while (st1 != NULL) {
        curr = pop(&st1);
        push(&st2, curr);

        if (curr->left != NULL)
            push(&st1, curr->left);
        if (curr->right != NULL)
            push(&st1, curr->right);
    }

    while (st2 != NULL) {
        curr = pop(&st2);
        printf("%d ", curr->data);
    }
    printf("\n");
}

// Function to insert a node as a left or right child of a given parent node
void insertNode(struct Node* parent, int data, char direction) {
    struct Node* new_node = newNode(data);
    
    if (direction == 'L' || direction == 'l') {
        if (parent->left == NULL) {
            parent->left = new_node;
            printf("Inserted %d as the left child of %d.\n", data, parent->data);
        } else {
            printf("Left child of %d already exists. Insertion failed.\n", parent->data);
            free(new_node);
        }
    } else if (direction == 'R' || direction == 'r') {
        if (parent->right == NULL) {
            parent->right = new_node;
            printf("Inserted %d as the right child of %d.\n", data, parent->data);
        } else {
            printf("Right child of %d already exists. Insertion failed.\n", parent->data);
            free(new_node);
        }
    } else {
        printf("Invalid direction. Use 'L' for left or 'R' for right.\n");
        free(new_node);
    }
}

// Function to find and print the parent of a given element
void printParent(struct Node* root, int value) {
    if (root == NULL) return;

    struct stack* st = NULL;
    push(&st, root);

    while (st != NULL) {
        struct Node* curr = pop(&st);

        if ((curr->left && curr->left->data == value) || 
            (curr->right && curr->right->data == value)) {
            printf("Parent of %d is %d.\n", value, curr->data);
            return;
        }

        if (curr->right) push(&st, curr->right);
        if (curr->left) push(&st, curr->left);
    }

    printf("Element %d has no parent (it may be the root or not present).\n", value);
}

// Function to calculate and return the depth of the tree
int calculateDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void printDepth(struct Node* root) {
    int depth = calculateDepth(root);
    printf("Depth of the tree is %d.\n", depth);
}

// Function to print the ancestors of a given element
int printAncestorsHelper(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;

    if (printAncestorsHelper(root->left, value) || printAncestorsHelper(root->right, value)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

void printAncestors(struct Node* root, int value) {
    printf("Ancestors of %d are: ", value);
    if (!printAncestorsHelper(root, value)) {
        printf("No ancestors found (element may not be present).\n");
    } else {
        printf("\n");
    }
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void printLeafNodeCount(struct Node* root) {
    int count = countLeafNodes(root);
    printf("Number of leaf nodes in the tree is %d.\n", count);
}

int main() {
    struct Node* root = NULL;
    int choice, val, parent_val;
    char direction;
    struct Node* temp;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Print parent of a node\n");
        printf("6. Print depth of the tree\n");
        printf("7. Print ancestors of a node\n");
        printf("8. Count leaf nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                if (root == NULL) {
                    root = newNode(val);
                    printf("Inserted %d as the root node.\n", val);
                } else {
                    printf("Enter the parent node value: ");
                    scanf("%d", &parent_val);
                    
                    temp = root;
                    struct stack* st = NULL;
                    push(&st, temp);
                    struct Node* parent = NULL;
                    
                    while (st != NULL) {
                        temp = pop(&st);
                        if (temp->data == parent_val) {
                            parent = temp;
                            break;
                        }
                        if (temp->right != NULL) push(&st, temp->right);
                        if (temp->left != NULL) push(&st, temp->left);
                    }
                    
                    if (parent != NULL) {
                        printf("Enter 'L' to insert as left child, 'R' to insert as right child: ");
                        scanf(" %c", &direction);
                        insertNode(parent, val, direction);
                    } else {
                        printf("Parent node with value %d not found.\n", parent_val);
                    }
                }
                break;

            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                break;

            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                break;

            case 5:
                printf("Enter the node value to find its parent: ");
                scanf("%d", &val);
                printParent(root, val);
                break;

            case 6:
                printDepth(root);
                break;

            case 7:
                printf("Enter the node value to find its ancestors: ");
                scanf("%d", &val);
                printAncestors(root, val);
                break;

            case 8:
                printLeafNodeCount(root);
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
