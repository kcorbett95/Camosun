/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   StatsMain.c
 * Author: C0527059
 *
 * Created on February 14, 2023, 8:43 a.m.
 */

#include "statistics.h"
//double avg(const double sum, const int count);
static void printStats(FILE *dest, const int count, const double
        mean, const double sdv);

/*
 * take cmd line arguments to read numbers from a given file, perform stats math
 * and send results to output file of the same filename
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        //print error if not enough arguments entered in cmd line
        fprintf(stderr, "usage: %s filename.txt \n", basename(argv[0]));
        return EXIT_FAILURE;
    }

    //open and read the input file
    FILE *infile;
    infile = fopen(argv[1], "r");
    //error handling, if the file is empty or incorrect filetype
    if (infile == NULL) {
        fprintf(stderr, "\nThe file could not be opened");
        return EXIT_FAILURE;
    }

    //sum values from file, pass to mean function
    double x, sum, sumsq = 0.0;
    int count = 0;
    while (fscanf(infile, "%lf", &x) == 1) {
        //printf("*****DEBUG***** value = %lf ", x);
        count++;
        sum = sum + x;
        sumsq = sumsq + x*x;
        //printf("\n*****DEBUG***** count = %d, sum = %lf, sumsq = %lf\n", count, sum, sumsq);
    }
    //close the file
    fclose(infile);
    
    //Compute mean and Sample Std Dev
    double m, sdv = 0.0;

    m = avg(sum, count);

    sdv = ssdev(sum, sumsq, count);

    printf("%s contains: %d Values\n", argv[1], count);
    printf("Mean: %lf\n", m);
    printf("Sample Standard Deviation: %lf\n", sdv);

    return (EXIT_SUCCESS);
}

void printStats(FILE *dest, const int count, const double
        mean, const double sdv) {

}
