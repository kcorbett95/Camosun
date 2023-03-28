/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   queue.h
 * Author: C0527059
 *
 * Created on March 28, 2023, 9:17 a.m.
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

// The following 3 lines must all be in agreement
typedef int ItemType;
#define ITEM_PROMPT "an integer"
#define ITEM_FORMAT "%d"

// A node for a singly-linked list
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *dataPtr;
} ListNode;

// A queue data structure
typedef struct Queue {
    ListNode *front;
    ListNode *rear;
    int size; // Number of items currently in the queue
} Queue;

// enqueue and dequeue use void pointers so that they are
// completely generic, i.e., they store a pointer to anything.

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
void *enqueueRear (Queue *queuePtr, void *newItem);

/* Add an item to the front of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
void *enqueueFront (Queue *queuePtr, void *newItem);

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
void *dequeueFront (Queue *queuePtr);

/* Removes an item from the rear of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
void *dequeueRear (Queue *queuePtr);

/* Returns:  number of items in the queue */
int queueSize (const Queue queue);

/* Print the contents of the queue to the specified stream
 * Note that this "extra" function is the only one that
 * uses ItemType
 */
void printQueue (const Queue queue, FILE *stream);


#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */

