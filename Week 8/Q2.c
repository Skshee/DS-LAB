#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Concatenate two doubly linked lists and return the head of the concatenated list
struct Node* concatenate(struct Node* X1, struct Node* X2) {
    if (X1 == NULL) {
        return X2; // If the first list is empty, return the second list
    }

    struct Node* temp = X1;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the end of the first list
    }

    temp->next = X2; // Link the last node of the first list to the head of the second list
    if (X2 != NULL) {
        X2->prev = temp; // Set the previous pointer of the second list's head
    }

    return X1; // Return the head of the concatenated list
}

// Print the elements of a doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Print data of each node
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Create a doubly linked list with 'n' nodes
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL) {
            head = newNode; // Initialize the head if the list is empty
            temp = head;
        } else {
            temp->next = newNode; // Append the new node to the list
            newNode->prev = temp;
            temp = temp->next;
        }
    }

    return head; // Return the head of the newly created list
}

int main() {
    int n1, n2;
    printf("Enter the number of nodes for the first list: ");
    scanf("%d", &n1);
    struct Node* X1 = createList(n1);
    printf("Enter the number of nodes for the second list: ");
    scanf("%d", &n2);
    struct Node* X2 = createList(n2);

    // Concatenate the two lists
    struct Node* concatenatedList = concatenate(X1, X2);
    
    // Print the concatenated list
    printf("Concatenated list: ");
    printList(concatenatedList);

    return 0;
}
