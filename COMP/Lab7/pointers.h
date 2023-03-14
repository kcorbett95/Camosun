/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   pointers.h
 * Author: C0527059
 *
 * Created on March 14, 2023, 8:52 a.m.
 */

#ifndef POINTERS_H
#define POINTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <math.h>

typedef float WORD; // Must be compatible with next line
#define WORD_FORMAT "%f " // Must be compatible with previous line
#define N_NUMS 10
const static WORD START = 0.0013;

void swap (WORD *x, WORD *y);
void printVector (const WORD *vec, const int N);
void printBytes (const WORD *vec, const int N);
void printBytesReverseEndian (const WORD *vec, const int N);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* POINTERS_H */

