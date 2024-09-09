#include<stdio.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char ele) {
    if(top == MAX - 1)
        printf("Stack Overflow");
    else
        stack[++top] = ele;
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow");
        return '\0';
    }
    else
        return stack[top--];
}

int isOperand(char ele) {
    if((ele >= 'A' && ele <= 'Z') || (ele >= 'a' && ele <= 'z'))
        return 1;
    else
        return 0;
}

void display() {
    int i;
    for(i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    char prefix[MAX];
    char ele;
    int i, j;
    printf("Enter the prefix expression:\n");
    scanf("%s", prefix);
    i = strlen(prefix) - 1;
    for(; i >= 0; i--) {
        ele = prefix[i];
        if(isOperand(ele)) {
            push(ele);
        } else {
            char op1 = pop();
            char op2 = pop();
            push('(');
            push(op2);
            push(ele);
            push(op1);
            push(')');
        }
    }
    display();
    return 0;
}