//Complex Math function library
#include "complex.h"
//Add two complex numbers
complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}
//Subtract two complex numbers
complex subtract(complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}
//Multiply two complex numbers
complex multiply(complex a, complex b) {
    complex result;
    result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
    return result;
}
//Divide two complex numbers
complex divide(complex a, complex b) {
    complex result;
    double denominator = (b.real * b.real) + (b.imaginary * b.imaginary);
    result.real = ((a.real * b.real) + (a.imaginary * b.imaginary)) / denominator;
    result.imaginary = ((a.imaginary * b.real) - (a.real * b.imaginary)) / denominator;
    return result;
}
//print rectangular components of a complex number
void print_complex(complex z) {
    printf("%9.4lf %+9.4lfi\n", z.real, z.imaginary);
}
//compute complex conjugate of a complex number
complex conjugate (const complex a){
    complex result;
    result.real = (a.real);
    result.imaginary = (-a.imaginary);
    return result;
}
//compute polar magnitude of a complex number
double magnitude(const complex a){
    double result;
    result = sqrt(((a.real * a.real)) + ((a.imaginary * a.imaginary)));
    return result;
}
//compute angle of polar complex number
double angle(const complex a){
  return atan2(a.imaginary, a.real);
}