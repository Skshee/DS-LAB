#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

// Insert a new node at the end of the circular doubly linked list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }

    // Find the last node
    struct Node* last = head->prev;

    // Insert the new node at the end
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;

    return head; // Return the head of the modified list
}

// Delete a node with a specific value from the circular doubly linked list
struct Node* delete(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* prevNode = NULL;

    // Search for the node to be deleted
    do {
        if (current->data == data) {
            if (current->next == current) {
                // If it's the only node in the list
                free(current);
                return NULL;
            }

            // Update the links to exclude the current node
            if (current == head) {
                head = head->next; // Update head if it's the node to be deleted
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            free(current);
            return head;
        }
        prevNode = current;
        current = current->next;
    } while (current != head);

    printf("Element %d not found in the list.\n", data);
    return head; // Return the head of the modified list
}

// Print the elements of the circular doubly linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    // Menu-driven program
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;
            case 3:
                printf("The list is: ");
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
