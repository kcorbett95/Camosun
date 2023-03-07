/* 
 * File:   searchMain.c
 * Author: C0527059
 *
 * Created on March 7, 2023, 8:38 a.m.
 */

#include "arraySearch.h"

/*
 * 
 */
int main(int argc, char *argv[]) {

    //print error if not enough arguments entered in cmd line
    if (argc != 3) {
        fprintf(stderr, "usage: search filename nNumbers \n");
        return EXIT_FAILURE;
    }

    //open and read the input file
    FILE *infile;
    //error handling, if the file is empty or incorrect filetype, will display error message based on errno
    if ((infile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "The file %s could not be opened, error: %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }
    //convert number of values to int
    int nNum = 0;
    if (sscanf(argv[2], "%d", &nNum) != 1) {
        fprintf(stderr, "Error converting %s to integer\n", argv[2]);
        return EXIT_FAILURE;
    }
    //printf("*****DEBUG***** int = %d\n", nNum);
    //check if number of values is positive
    if (nNum < 0) {
        fprintf(stderr, "number of values must be positive\n");
        return EXIT_FAILURE;
    }

    //allocate memory for array
    int *intArray = (int*) malloc(nNum * sizeof (int));
    //read file, check for number of entries read is correct
    if (fread(intArray, sizeof (int), nNum, infile) != nNum) {
        fprintf(stderr, "Error reading %d values from file %s\n", nNum, argv[1]);
        return EXIT_FAILURE;
    }
    //close file
    fclose(infile);


    int query;
    //prompt user for search input repeatedly
    while (loop) {
        fprintf(stdout, "Enter a number to search for (q to quit): ");
        if (scanf("%d", &query) != 1) {
            fprintf(stdout, "Goodbye");
            break;
        }

        //search file, return instances where query value occurs in file
        int index = linearSearch(query, intArray, nNum);
        if (index < 0) {
            printf("File %s does not contain %d\n", argv[1], query);
        } else {
            printf("File %s contains %d at index %d\n", argv[1], query, linearSearch(query, intArray, nNum));
            continue;
        }

    }
    //release memory to heap after exiting loop
    free(intArray);

    return (EXIT_SUCCESS);
}

