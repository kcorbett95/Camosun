/* Tests for Queue library.
 *
 * Dale Shpak
 * March 25, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef enum {QUIT=-1, ENQUEUEFRONT, DEQUEUEFRONT, ENQUEUEREAR, DEQUEUEREAR, PRINT, N_CHOICES} Choice;

int main(int ac, char *av[]) {
    Queue queue = {NULL, NULL, 0};

    int done = 0;
    while (!done) {
        Choice choice;
	int nValid;
        do {
            printf("Enter %d to add to front of queue, \n%d to remove from front of queue, \n%d to add to rear of queue, \n%d to remove from rear of queue, \nor %d to print contents "
		   "(%d to quit): ", ENQUEUEFRONT, DEQUEUEFRONT, ENQUEUEREAR, DEQUEUEREAR, PRINT, QUIT);
            nValid = scanf("%d", &choice);
	    while (getchar() != '\n') { } // Get rid of rest of line
        } while (nValid != 1 || choice < QUIT || choice >= N_CHOICES);

        switch (choice) {
            case DEQUEUEFRONT: {
	    ItemType *itemPtr;
	    if ((itemPtr = (ItemType *)dequeueFront(&queue)) != NULL) {
		printf("Removed " ITEM_FORMAT "\n", *itemPtr);
		free (itemPtr);
	    } else {
		printf("Queue is empty\n");
	    }
	    break;
	}

	case ENQUEUEFRONT: {
	    ItemType *itemPtr = (ItemType *) malloc (sizeof(ItemType));
	    if (itemPtr == NULL) {
		fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
		return EXIT_FAILURE;
	    }

	    printf ("Enter " ITEM_PROMPT ": ");
	    if (scanf(ITEM_FORMAT, itemPtr) != 1) {
		fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
		break;
	    }

	    if ((itemPtr = enqueueFront(&queue, itemPtr)) != NULL) {
		printf("Added " ITEM_FORMAT "\n", *itemPtr);
	    } else {
		fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
		return EXIT_FAILURE;
	    }
	    break;
	}
        
	case DEQUEUEREAR: {
	    ItemType *itemPtr;
	    if ((itemPtr = (ItemType *)dequeueRear(&queue)) != NULL) {
		printf("Removed " ITEM_FORMAT "\n", *itemPtr);
		free (itemPtr);
	    } else {
		printf("Queue is empty\n");
	    }
	    break;
	}

	case ENQUEUEREAR: {
	    ItemType *itemPtr = (ItemType *) malloc (sizeof(ItemType));
	    if (itemPtr == NULL) {
		fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
		return EXIT_FAILURE;
	    }

	    printf ("Enter " ITEM_PROMPT ": ");
	    if (scanf(ITEM_FORMAT, itemPtr) != 1) {
		fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
		break;
	    }

	    if ((itemPtr = enqueueRear(&queue, itemPtr)) != NULL) {
		printf("Added " ITEM_FORMAT "\n", *itemPtr);
	    } else {
		fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
		return EXIT_FAILURE;
	    }
	    break;
	}
	    
	case PRINT: {
	    printf ("%d Items currently in the queue:\n", queueSize(queue));
	    printQueue (queue, stdout);
	    break;
	}
	    
	case QUIT: {
	    done = 1;
	    break;
	}

	default: {
	    fprintf(stderr, "Invalid choice entered");
	    break;
	}
        }
    }

    printf ("%d Items remaining in the queue:\n", queueSize(queue));
    printQueue (queue, stdout);


    return EXIT_SUCCESS;
}
