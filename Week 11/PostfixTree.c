#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct Node {
    char data;
    struct Node *left, *right;
};


struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to evaluate the expression tree
int evaluate(struct Node* root) {
    if (root == NULL)
        return 0;
    if (isdigit(root->data))
        return root->data - '0'; // Convert char to int

    // Evaluate left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Perform the operation based on the current node
    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return rightEval != 0 ? leftEval / rightEval : 0; // Avoid division by zero
    }
    return 0;
}

// Function to construct an expression tree from a postfix expression
struct Node* constructTree(char* postfix) {
    struct Node** stack = (struct Node**)malloc(100 * sizeof(struct Node*));
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else {
            struct Node* newNode = createNode(postfix[i]);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    struct Node* root = stack[top--];
    free(stack);
    return root;
}

// Main function
int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Construct the expression tree
    struct Node* root = constructTree(postfix);

    printf("Evaluation of Postfix Expression: %d\n", evaluate(root));

    return 0;
}
