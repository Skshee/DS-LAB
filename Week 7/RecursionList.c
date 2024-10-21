#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
} node;


void insert_tail(node** list, node* cur, int ele) {
    if (!cur) {
        cur = malloc(sizeof(*cur));
        cur -> next = NULL;
        cur -> data = ele;
        *list = cur;
        return;
    }
    if (!cur -> next) {
        node* insert = malloc(sizeof(*insert));
        insert -> data = ele;
        cur -> next = insert;
        return;
    }
    insert_tail(list, cur -> next, ele);
}


void traverse(node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head -> data);
    traverse(head -> next);
}

int main() {
    printf("1. Insert into list\n2. Traverse list\n3. Exit\nEnter choice: ");
    int ch;
    scanf("%d", &ch);
    node** head = malloc(sizeof(*head));
    while (1) {
        int ele;
        switch(ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                insert_tail(head, *head, ele);
                break;
            case 2:
                traverse(*head); break;
            case 3: return 0;
            default: printf("Invalid choice\n");
        }
        printf("Enter choice: ");
        scanf("%d", &ch);
    }
}