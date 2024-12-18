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


node* insert_before(node* head, int ele, int ins) {
    if (head -> data == ele) {
        node* insert = malloc(sizeof(*insert));
        insert -> data = ins;
        insert -> next = head;
        head = insert;
        return head;
    }
    node* cur = head;
    for (; cur -> next; cur = cur -> next)
        if (cur -> next -> data == ele)
            break;
    node *insert = malloc(sizeof(*insert));
    insert -> data = ins;
    insert -> next = cur -> next;
    cur -> next = insert;
    return head;
}


node* insert_sort(node* head, int ele) {
    if (!head) {
        head = malloc(sizeof(*head));
        head -> next = NULL;
        head -> data = ele;
        return head;
    }
    node* insert = malloc(sizeof(*insert));
    insert -> data = ele;
    node* cur = head;
    for (; cur -> next; cur = cur -> next)
        if (cur -> data > ele) {
            head = insert_before(head, cur -> data, ele);
            return head;
        }
    if (cur -> data > ele) {
        head = insert_before(head, cur -> data, ele);
        return head;
    }
    cur -> next = insert;
    insert -> next = NULL;
    return head;
}


node* merge(node* head1, node* head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    node* newhead, * cur1, * cur2;
    if (head1 -> data <= head2 -> data) {
        newhead = head1;
        cur1 = newhead;
        cur2 = head2;
    }
    else {
        newhead = head2;
        cur1 = newhead;
        cur2 = head1;
    }
    while(cur1 && cur2) {
        for (; cur1 -> next && (cur1 -> next -> data <= cur2 -> data); cur1 = cur1 -> next);
        node* temp1 = cur1 -> next, * temp2 = cur2;
        cur1 -> next = cur2;
        cur2 = temp1;
        cur1 = temp2;
    }
    return newhead;
}

int main() {
    printf("1. Insert into list 1\n2. Insert into list 2\n"
           "3. Merge into list 1\n4. Traverse list 1\n"
           "5. Traverse list 2\n6. Exit\nEnter choice: ");
    int ch;
    scanf("%d", &ch);
    node* head1 = NULL, * head2 = NULL;
    while (1) {
        int ele;
        switch(ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                head1 = insert_sort(head1, ele);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                head2 = insert_sort(head2, ele);
                break;
            case 3:
                head1 = merge(head1, head2);
                head2 = NULL;
                break;
            case 4: traverse(head1); break;
            case 5: traverse(head2); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
        printf("Enter choice: ");
        scanf("%d", &ch);
    }
}