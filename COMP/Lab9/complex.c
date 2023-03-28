//Complex Math function library
#include "complex.h"

complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

complex subtract(complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

complex multiply(complex a, complex b) {
    complex result;
    result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
    return result;
}

complex divide(complex a, complex b) {
    complex result;
    double denominator = (b.real * b.real) + (b.imaginary * b.imaginary);
    result.real = ((a.real * b.real) + (a.imaginary * b.imaginary)) / denominator;
    result.imaginary = ((a.imaginary * b.real) - (a.real * b.imaginary)) / denominator;
    return result;
}

void print_complex(complex z) {
    printf("%9.4lf %+9.4lfi\n", z.real, z.imaginary);
}

complex conjugate (const complex a){
    complex result;
    result.real = (a.real);
    result.imaginary = (0 - a.imaginary);
    return result;
}

double magnitude(const complex a){
    double result;
    result = sqrt(((a.real * a.real)) + ((a.imaginary * a.imaginary)));
    return result;
}

double angle(const complex a){
  double result;
if(a.imaginary < 0){
    result = PI + atan2(a.imaginary, a.real);
}  
else result = atan2(a.imaginary, a.real);
}