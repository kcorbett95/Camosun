/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   statistics.h
 * Author: C0527059
 *
 * Created on February 14, 2023, 8:44 a.m.
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif


double avg(const double sum, const int count);
double ssdev(const double sum, const double sumsq, const int count);


#ifdef __cplusplus
}
#endif

#endif /* STATISTICS_H */

