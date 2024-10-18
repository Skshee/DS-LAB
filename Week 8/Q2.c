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
void printList(struct Node
