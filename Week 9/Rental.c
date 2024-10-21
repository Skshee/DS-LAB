#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char userName[50];
    int time;
    struct Node *next, *prev;
};

// Function to create a new node
struct Node* createNode(char* name, int time) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->userName, name);
    newNode->time = time;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to add a user to the circular doubly linked list
void addUser(struct Node** head, char* name, int time) {
    struct Node* newNode = createNode(name, time);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to simulate the renting system
void simulateRenting(struct Node** head) {
    struct Node* current = *head;
    while (current) {
        printf("Washing Machine in use by: %s for %d minutes\n", current->userName, current->time);
        current = current->next;
        if (current == *head) break;  // Completed one cycle
    }
}

// Main function
int main() {
    struct Node* queue = NULL;
    int n, time;
    char name[50];

    printf("Enter the number of users: ");
    scanf("%d", &n);

    // Input details for each user
    for (int i = 0; i < n; i++) {
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", name);
        printf("Enter the time (in minutes) for %s: ", name);
        scanf("%d", &time);
        addUser(&queue, name, time);
    }

    // Simulate the washing machine renting system
    printf("\nWashing Machine Renting System Simulation:\n");
    simulateRenting(&queue);

    return 0;
}
