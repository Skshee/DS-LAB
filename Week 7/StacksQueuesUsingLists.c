#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
} node;


void traverse(node* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    for (node* cur = head; cur; cur = cur -> next)
        printf("%d ", cur -> data);
    printf("\n");
}


node* push(node* head, int ele) {
    if (!head) {
        head = malloc(sizeof(*head));
        head -> next = NULL;
        head -> data = ele;
        return head;
    }
    node* insert = malloc(sizeof(*insert));
    insert -> data = ele;
    insert -> next = head;
    return insert;
}


node* pop(node* head) {
    if(!head) {
        printf("Underflow");
        return NULL;
    }
    printf("Removed %d\n", head -> data);
    node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}


node* enqueue(node* head, int ele) {
    node* insert = malloc(sizeof(*insert));
    insert -> data = ele;
    insert -> next = NULL;
    if(!head) {
        head = insert;
        return head;
    }
    node* cur = head;
    for (;cur -> next; cur = cur -> next);
    cur -> next = insert;
    return head;
}


node* delete_end(node* head) {
    if (!head) {
        printf("Underflow");
        return NULL;
    }
    if (!head -> next) {
        printf("Removed %d\n", head -> data);
        free(head);
        return NULL;
    }
    node* cur = head;
    for (; cur -> next -> next; cur = cur -> next);
    node* temp = cur -> next;
    cur -> next = NULL;
    printf("Removed %d\n", temp -> data);
    free(temp);
    return head;
}

int main() {
    printf("1. Push to stack\n2. Pop from stack\n3. Traverse stack\n\n"
           "4. Enqueue to queue\n5. Dequeue from queue\n6. Traverse queue\n\n"
           "7. Push to deque\n8. Enqueue to deque\n"
           "9. Pop from deque\n10. Remove from end from deque\n"
           "11. Traverse deque\n\n12. Exit\n"
           "Enter choice: ");
    int ch;
    scanf("%d", &ch);
    node* stackhead = NULL, * queuehead = NULL, * dequehead = NULL;
    while (1) {
        int ele;
        switch(ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                stackhead = push(stackhead, ele);
                break;
            case 2:
                stackhead = pop(stackhead);
                break;
            case 3: traverse(stackhead); break;

            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                queuehead = enqueue(queuehead, ele);
                break;
            case 5:
                queuehead = pop(queuehead);
                break;
            case 6: traverse(queuehead); break;
                
            case 7:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                dequehead = push(dequehead, ele);
                break;
            case 8:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                dequehead = enqueue(dequehead, ele);
                break;
            case 9: 
                dequehead = pop(dequehead);
                break;
            case 10: 
                dequehead = delete_end(dequehead);
                break;
            case 11: traverse(dequehead); break;

            case 12: return 0;
            default: printf("Invalid choice\n");
        }
        printf("Enter choice: ");
        scanf("%d", &ch);
    }
}