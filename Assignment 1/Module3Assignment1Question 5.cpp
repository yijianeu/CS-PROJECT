#include <stdio.h>
#include <stdlib.h>

// This program implements a queue using linked list
// This program get ideas from https://www.digitalocean.com/community/tutorials/queue-in-c

struct Node {
    int data; // This line defines the data of the node
    struct Node* next; // This line defines the next pointer of the node
};

// Enqueue function
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // This line allocates memory for the new node
    newNode->data = data; // This line assigns the data to the new node
    newNode->next = NULL; // This line sets the next pointer of the new node to NULL
    if (*rear) (*rear)->next = newNode; // This line sets the next pointer of the rear node to the new node
    else *front = newNode; // This line sets the front pointer to the new node
    *rear = newNode; // This line sets the rear pointer to the new node
}

// Dequeue function
int dequeue(struct Node** front, struct Node** rear) {
    if (!*front) return -1; // This line returns -1 if the front pointer is NULL
    struct Node* temp = *front; // This line creates a temporary node and assigns the front pointer to it
    int data = temp->data; // This line assigns the data of the temporary node to the data variable
    *front = (*front)->next; // This line sets the front pointer to the next node
    if (!*front) *rear = NULL; // This line sets the rear pointer to NULL
    free(temp); // This line frees the memory of the temporary node
    return data;
}

// Main function
int main() {
    struct Node* front = NULL; // This line initializes the front pointer to NULL
    struct Node* rear = NULL; // This line initializes the rear pointer to NULL
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    printf("Dequeued: %d\n", dequeue(&front, &rear));
    enqueue(&front, &rear, 3);
    printf("Dequeued: %d\n", dequeue(&front, &rear));
    printf("Dequeued: %d\n", dequeue(&front, &rear));
    return 0;
}

