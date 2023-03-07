/* 
 * File:   StatsMain.c
 * Author: C0527059
 *
 * Created on February 14, 2023, 8:43 a.m.
 */

#include "statistics.h"
#define PREFIX "Result_"

static void printStats(FILE *outfile, const int count, const double
        mean, const double sdv);

/*
 * take cmd line arguments to read numbers from a given file, perform stats math
 * and send results to output file of the same filename
 */
int main(int argc, char *argv[]) {
    //print error if not enough arguments entered in cmd line
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename.txt \n", basename(argv[0]));
        return EXIT_FAILURE;
    }

    //open and read the input file
    FILE *infile;
    //error handling, if the file is empty or incorrect filetype, will display error message based on errno
    if ((infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "The file %s could not be opened, error: %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    //math from values read from input file
    double x, sum, sumsq = 0.0;
    int count = 0;
    while (fscanf(infile, "%lf", &x) == 1) {
        //printf("*****DEBUG***** value = %lf ", x);
        count++;
        sum = sum + x;
        sumsq = sumsq + x*x;
        //printf("\n*****DEBUG***** count = %d, sum = %lf, sumsq = %lf\n", count, sum, sumsq);
    }

    //close the input file
    fclose(infile);

    //Compute mean and Sample Std Dev
    //error handling for #entries
    if(count<2){
        fprintf(stderr,"\nInsufficient Entries for Sdv function");
        return EXIT_FAILURE;
    }
    double m, sdv = 0.0;
    m = avg(sum, count);
    sdv = ssdev(sum, sumsq, count);

    //Allocate memory for output file
    int nChar = strlen(PREFIX) + strlen(argv[1]) + 1; //length of filename array
    char *filename = (char*) malloc(nChar); //request chunk of memory for output file
    strncpy(filename, PREFIX, strlen(PREFIX)); //add prefix to output file name
    strncat(filename, argv[1], strlen(argv[1])); //concatenate

    //Open or create output file if it does not exist, error handling if unable to open or create
    FILE *outfile;
    if ((outfile = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "The file %s could not be opened, error: %s\n", filename, strerror(errno));
        EXIT_FAILURE;
    }
    free(filename);

    //Print stats values to console and output file
    printStats(outfile, count, m, sdv);
    printStats(stdout, count, m, sdv);

    //close output file
    fclose(outfile);

    return (EXIT_SUCCESS);
}

void printStats(FILE *outfile, const int count, const double
        mean, const double sdv) {
    //print values to output file
    fprintf(outfile, "%d Values\n", count);
    fprintf(outfile, "Mean = %lf\n", mean);
    fprintf(outfile, "Sample Standard Deviation = %lf\n", sdv);

}
