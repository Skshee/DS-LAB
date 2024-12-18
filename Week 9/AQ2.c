
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff, power;
    struct Node *prev, *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

// Function to insert a node in the circular doubly linked list
void insertEnd(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    do {
        insertEnd(&result, p1->coeff, p1->power);
        p1 = p1->next;
    } while (p1 != poly1);

    do {
        insertEnd(&result, p2->coeff, p2->power);
        p2 = p2->next;
    } while (p2 != poly2);

    return result;
}

// Function to display a polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    do {
        printf("%dx^%d ", temp->coeff, temp->power);
        if (temp->next != head) printf("+ ");
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;

    // Polynomial 1: 3x^2 + 2x + 1
    insertEnd(&poly1, 3, 2);
    insertEnd(&poly1, 2, 1);
    insertEnd(&poly1, 1, 0);

    // Polynomial 2: 4x + 2
    insertEnd(&poly2, 4, 1);
    insertEnd(&poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Result of Addition: ");
    display(result);

    return 0;
}
