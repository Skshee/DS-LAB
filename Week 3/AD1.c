#include<stdio.h>
#define MAX 20

int stack[MAX];
int top[MAX];
int boundary[MAX];

void initialise(int n)
{
    for (int i = 0; i < n; i++)
        boundary[i] = top[i] = (MAX / n) * i - 1;
    boundary[n] = MAX - 1;  // set the boundary for the last stack
}

void push(int i, int n, int val)
{
    if (top[i] == boundary[i + 1] || top[i] == MAX - 1) {
        printf("Stack %d is full\n", i + 1);
    } else {
        stack[++top[i]] = val;
    }
}

int pop(int i)
{
    if (top[i] == boundary[i]) {
        printf("Stack %d is empty\n", i + 1);
        return -1;  // returning -1 to indicate empty stack
    } else {
        return stack[top[i]--];
    }
}

int main() {
    int n, choice, stackNum, val;
    printf("Enter the number of stacks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of stacks.\n");
        return 1;
    }

    initialise(n);
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                printf("Enter the stack number (1 to %d): ", n);
                scanf("%d", &stackNum);
                if (stackNum < 1 || stackNum > n) {
                    printf("Invalid stack number\n");
                    break;
                }
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(stackNum - 1, n, val);
                break;

            case 2:  
                printf("Enter the stack number (1 to %d): ", n);
                scanf("%d", &stackNum);
                if (stackNum < 1 || stackNum > n) {
                    printf("Invalid stack number\n");
                    break;
                }
                val = pop(stackNum - 1);
                if (val != -1) {
                    printf("Popped value: %d\n", val);
                }
                break;

            case 3: 
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
