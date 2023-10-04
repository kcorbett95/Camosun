/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   spherical.hpp
 * Author: c0527059
 *
 * Created on September 27, 2023, 3:04 PM
 */

#ifndef SPHERICAL_HPP
#define SPHERICAL_HPP

typedef struct {
    double radius;  //magnitude, >0
    double azimuth; //-pi to pi
    double inclination; //-pi to pi
} SphericalCoords;

double *sphericalToRectangular (double r, double azimuth, double inclination=(M_PI/2));
SphericalCoords rectangularToSpherical (double x, double y, double z=0);  
inline double getRadius (double x, double y, double z=0);

#endif /* SPHERICAL_HPP */

