/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: C0527059
 *
 * Created on March 21, 2023, 9:54 a.m.
 */

#include "complex.h"



int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <complex number> <complex number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    complex a, b;
    char mustbeIorJ[2];
    if (sscanf(argv[1], "%lf%lf%1[ij]", &a.real, &a.imaginary, mustbeIorJ) != 3) {
        printf("Invalid complex number: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (sscanf(argv[2], "%lf%lf%1[ij]", &b.real, &b.imaginary, mustbeIorJ) != 3) {
        printf("Invalid complex number: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    printf("a            = " Z_FORMAT "\n", a.real, a.imaginary);
    printf("b            = " Z_FORMAT "\n", b.real, b.imaginary);
    printf("a + b        = " Z_FORMAT "\n", add(a, b).real, (add(a, b).imaginary));
    printf("a - b        = " Z_FORMAT "\n", subtract(a, b).real, (subtract(a, b).imaginary));
    printf("a * b        = " Z_FORMAT "\n", multiply(a, b).real, (multiply(a, b).imaginary));
    printf("a / b        = " Z_FORMAT "\n", divide(a, b).real, (divide(a, b).imaginary));
    printf("a Conjugate  = " Z_FORMAT "\n", conjugate(a).real, (conjugate(a).imaginary));
    printf("b Conjugate  = " Z_FORMAT "\n", conjugate(b).real, (conjugate(b).imaginary));
    printf("a: Magnitude = %9.4lf, angle = %7.4lf rads \n", magnitude(a), angle(a));
    printf("B: Magnitude = %9.4lf, angle = %7.4lf rads \n", magnitude(b), angle(b));
    return EXIT_SUCCESS;
}


