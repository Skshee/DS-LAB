
#include <stdio.h>
#include <stdlib.h>
#define HEAD 0
#define TAIL 1

/** Node of the doubly linked list */
typedef struct node {
    int data;                  // The data stored in the node
    struct node* prev;        // The pointer to the previous node
    struct node* next;        // The pointer to the next node
} node;

/** Inserts an element at the tail end of the list */
void insert_tail(node** list, int ele) {
    node* insert = malloc(sizeof(*insert));
    insert->data = ele;
    insert->next = NULL;
    if (!list[HEAD]) {
        insert->prev = NULL;
        list[HEAD] = list[TAIL] = insert;
    } else {
        list[TAIL]->next = insert;
        insert->prev = list[TAIL];
        list[TAIL] = insert;
    }
}

/** Inserts an element at the head of the list */
void insert_head(node** list, int ele) {
    node* insert = malloc(sizeof(*insert));
    insert->data = ele;
    insert->prev = NULL;
    if (!list[HEAD]) {
        insert->next = NULL;
        list[HEAD] = list[TAIL] = insert;
    } else {
        insert->next = list[HEAD];
        list[HEAD]->prev = insert;
        list[HEAD] = insert;
    }
}

/** Traverses the list */
void traverse(node* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    for (node* cur = head; cur; cur = cur->next)
        printf("%d ", cur->data);  // Added space for better formatting
    printf("\n");
}

/** Adds two numbers represented as linked lists */
node** add(node** num1, node** num2) {
    node** sum = malloc(2 * sizeof(*sum));
    sum[HEAD] = sum[TAIL] = NULL;  // Initialize sum list
    node* cur1 = num1[TAIL];
    node* cur2 = num2[TAIL];
    int carry = 0;

    while (cur1 || cur2 || carry) {
        int digit = carry;
        if (cur1) {
            digit += cur1->data;
            cur1 = cur1->prev;
        }
        if (cur2) {
            digit += cur2->data;
            cur2 = cur2->prev;
        }
        carry = digit / 10;
        digit %= 10;
        insert_head(sum, digit);
    }
    return sum;
}

/** Frees the linked list */
void free_list(node* head) {
    node* current = head;
    while (current) {
        node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    printf("Enter the numbers: ");
    node** num1 = malloc(2 * sizeof(*num1));
    node** num2 = malloc(2 * sizeof(*num2));
    num1[HEAD] = num1[TAIL] = NULL; // Initialize num1
    num2[HEAD] = num2[TAIL] = NULL; // Initialize num2

    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch < '0' || ch > '9') {
            printf("Invalid number\n");
            return 1;
        }
        insert_tail(num1, ch - '0');
    }
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch < '0' || ch > '9') {
            printf("Invalid number\n");
            return 1;
        }
        insert_tail(num2, ch - '0');
    }

    node** sum = add(num1, num2);
    printf("The sum is: ");
    traverse(sum[HEAD]);

    // Free the lists
    free_list(num1[HEAD]);
    free_list(num2[HEAD]);
}