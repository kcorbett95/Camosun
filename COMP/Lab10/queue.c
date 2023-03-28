/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "queue.h"

// Add an item to the front of the dynamically-allocated queue.
void *enqueueFront(Queue *queuePtr, void *newItem) {
    // Allocate memory for a new node
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    // Set the data pointer of the new node to the item to be added
    newNode->dataPtr = newItem;
    newNode->next = NULL;
    newNode->prev = queuePtr->rear;
    // If the queue is empty, set both the front and rear pointers to the new node
    if (queuePtr->front == NULL) {
        newNode->next = NULL;
        queuePtr->rear = newNode;
    } else{
        newNode->next = queuePtr->front;
       queuePtr->front->prev = newNode; 
    }
    queuePtr->front = newNode;
    // Increment the size counter and return a pointer to the added item
    queuePtr->size++;
    return newNode->dataPtr;
}

// Add an item to the rear of the dynamically-allocated queue.
void *enqueueRear(Queue *queuePtr, void *newItem) {
    // Allocate memory for a new node
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    // Set the data pointer of the new node to the item to be added
    newNode->dataPtr = newItem;
    newNode->next = NULL;
    newNode->prev = queuePtr->rear;
    // If the queue is empty, set both the front and rear pointers to the new node
    if (queuePtr->rear == NULL) {
        newNode->prev = NULL;
        queuePtr->front = newNode;
    } else{
        newNode->prev = queuePtr->rear;
       queuePtr->rear->next = newNode; 
    }
    queuePtr->rear = newNode;
    // Increment the size counter and return a pointer to the added item
    queuePtr->size++;
    return newNode->dataPtr;
}

// Removes an item from the front of the queue.
void *dequeueFront(Queue *queuePtr) {
    // If the queue is empty, return NULL
    if (queuePtr->front == NULL) {
        return NULL;
    }
    // Store a pointer to the data of the head node and free the node
    ListNode *oldFront = queuePtr->front;
    void *removedData = oldFront->dataPtr;    
    queuePtr->front = oldFront->next;
    free(oldFront);
    // If the queue is now empty, set the rear pointer to NULL
    if (queuePtr->front == NULL) {
        queuePtr->rear = NULL;
    } else{
      queuePtr->front->prev = NULL;  
    }
    // Decrement the size counter and return a pointer to the removed item
    queuePtr->size--;
    return removedData;
}

// Removes an item from the rear of the queue.
void *dequeueRear(Queue *queuePtr) {
    // If the queue is empty, return NULL
    if (queuePtr->rear == NULL) {
        return NULL;
    }
    // Store a pointer to the data of the head node and free the node
    ListNode *oldRear = queuePtr->rear;
    void *removedData = oldRear->dataPtr;    
    queuePtr->rear = oldRear->prev;
    free(oldRear);
    // If the queue is now empty, set the front pointer to NULL
    if (queuePtr->rear == NULL) {
        queuePtr->front = NULL;
    } else{
      queuePtr->rear->next = NULL;  
    }
    // Decrement the size counter and return a pointer to the removed item
    queuePtr->size--;
    return removedData;
}

// Returns the number of items in the queue
int queueSize(const Queue queue) {
    return queue.size;
}

// Print the contents of the queue to the specified stream
void printQueue(const Queue queue, FILE *stream) {
    ListNode *currentNode = queue.front;
    while (currentNode != NULL) {
        fprintf(stream, ITEM_FORMAT "\n", *(ItemType *)currentNode->dataPtr);
        currentNode = currentNode->next;
    }
}