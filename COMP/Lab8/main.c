
/* 
 * File:   main.c
 * Author: C0527059
 *
 * Created on March 21, 2023, 8:32 a.m.
 */

#include "vectorMath.h"

/*Creates vectors containing numbers, prints them and manipulates them
 * 
 */
int main(int argc, char** argv) {
  Vector vec1 = {5, {1.0, 4.0, -7.2, -6.66, 1.23 }};
  Vector vec2 = {5, {-5.2, 11.1, 0.1, 9.9, 7.123 }};
  //Vector vec1 = {5, {'a', 'b', 'c', 'd', 'e' }};
  //Vector vec2 = {5, {'f', 'g', 'h', 'i', 'j' }};
  Vector vec3 = {7 };
  Vector result;

  printf("Vector #1  ");
  printVector (vec1, stdout);
  printf("Vector #2  ");
  printVector (vec2, stdout);

  // Check that the math operators work.
  if (vectorMath(vec1, vec2, &result, '+') != NULL) {
    printf ("Sum        ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Addition failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '-') != NULL) {
    printf ("Difference ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Subtraction failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '*') != NULL) {
    printf ("Product    ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Kronecker product failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '/') != NULL) {
    printf ("Quotient   ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Division failed\n");
  }

  // Check that the error handling works - Negative Testing
  // 1) Vector size mismatch
  if (vectorMath(vec1, vec3, &result, '/') != NULL) {
    printf ("Quotient   ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Division failed\n");
  }
  // 2) Invalid operator
  if (vectorMath(vec1, vec2, &result, '^') != NULL) {
    printf ("Exponent   ");
    printVector (result, stdout);
  } else {
    fprintf(stderr, "Exponentiation failed\n");
  }

  return EXIT_SUCCESS;

}

void printVector (const Vector v, FILE *stream){
    WORD *ptr = v.data;
    for (int i = 0; i < v.size; i++) {
        printf(WORD_FORMAT, *ptr++);
    }
    printf("\n");
}