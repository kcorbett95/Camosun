/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "CPP Header.h"
#include "spherical.hpp"
using namespace std;
//x = Rsinφcosθ
//y = Rsinφsinθ
//z = Rcosφ
double *sphericalToRectangular (double r, double azimuth, double inclination){
    double* rectangular = new double(3);
    double x = r*sin(inclination)*cos(azimuth);
    double y = r*sin(inclination)*sin(azimuth);
    double z = r*cos(inclination);
    
    rectangular[0] = x;
    rectangular[1] = y;
    rectangular[2] = z;
    return rectangular;
}
//R=sqrt(x^2+y^2+z^2)
//θ = atan(y/x)
//φ = arccos(z/R).
SphericalCoords rectangularToSpherical (double x, double y, double z){
    SphericalCoords spherical;
    spherical.radius = getRadius(x,y,z);
    spherical.azimuth = atan2(y,x);
    spherical.inclination = acos(z/spherical.radius);
    return spherical;
    
} 

inline double getRadius (double x, double y, double z){  
    return sqrt((x*x)+(y*y)+(z*z));
}
