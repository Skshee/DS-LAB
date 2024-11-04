#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char ele) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ele;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else
        return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

int isOperand(char ele) {
    return isalnum(ele); // Checks if character is alphanumeric
}

void display() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, j = 0;
    char ele;

    for (i = 0; i < strlen(infix); i++) {
        ele = infix[i];
        
        if (isOperand(ele)) {
            postfix[j++] = ele; // Add operand to postfix
        } else if (ele == '(') {
            push(ele); // Push '(' to stack
        } else if (ele == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Pop '(' from stack
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(ele)) {
                postfix[j++] = pop();
            }
            push(ele);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
