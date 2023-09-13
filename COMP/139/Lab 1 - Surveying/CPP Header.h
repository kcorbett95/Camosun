/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CPP Header.h
 * Author: C0527059
 *
 * Created on September 13, 2023, 2:41 PM
 */
#include <cstdlib>
#include <iostream>
#include <cmath>


#ifndef CPP_HEADER_H
#define CPP_HEADER_H

//Function prototypes for forward - referenced functions
void getUserInput(double &radius, double &pegDist, double &spacing);
void outputResults(const double angles[], const double distances[], const int numLights);

#endif /* CPP_HEADER_H */

