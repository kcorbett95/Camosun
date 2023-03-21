/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   complex.h
 * Author: C0527059
 *
 * Created on March 21, 2023, 9:55 a.m.
 */

#ifndef COMPLEX_H
#define COMPLEX_H
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif
    
#define Z_FORMAT "%9.4lf%+9.4lfi"
    
typedef struct {
    double real;
    double imaginary;
} complex;

complex add(complex a, complex b);
complex subtract(complex a, complex b);
complex multiply(complex a, complex b);
complex divide(complex a, complex b);
void print_complex(complex z);



#ifdef __cplusplus
}
#endif

#endif /* COMPLEX_H */

