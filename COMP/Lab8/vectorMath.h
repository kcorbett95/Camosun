/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   vectorMath.h
 * Author: C0527059
 *
 * Created on March 21, 2023, 8:32 a.m.
 */

#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#ifndef WORD
#define WORD double
#endif
//typedef double WORD; // Must be compatible with next line
#ifndef WORD_FORMAT
#error "You must define WORD_FORMAT as a compile-time option"
#endif

//#define WORD_FORMAT "%8.4lf" // Must be compatible with previous line
#define WORD_SIZE 10

typedef struct Vector {
    int size;
    WORD data[WORD_SIZE];
}Vector;

Vector *vectorMath (const Vector v1, const Vector v2, Vector *resPtr, const char op);
void printVector (const Vector v, FILE *stream);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VECTORMATH_H */

