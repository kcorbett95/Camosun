/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: C0527059 Kevin Corbett
 *
 * Created on January 10, 2023, 8:38 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359     //Pi definition for area calc

const int N_POWERS = 5;     //Number of powers to calc

int main(void) {
    double a, b, sum, diff, z, r, area;     //Declare variables
    
    printf("Enter two numbers: ");      //Prompt user and scan for two numbers
    scanf("%lf%lf", &a, &b);            //Insert two numbers into variables a and b
    
    sum = a + b;    //Add the two numbers
    diff = a - b;   //Sub the two numbers
    
    printf("The sum of %lf and %lf is %lf\n", a, b, sum);           //Print results of sum
    printf("The difference of %lf and %lf is %lf\n", a, b, diff);   //Print results of diff
    
    //For loop to print 5 powers using math.h function pow()
    for  (int k=0; k <= N_POWERS; k++){     
        z  = pow(a,k);                      
        printf("%lf raised to the power %d is %lf\n", a, k, z);
    }
    
    printf("Enter radius of circle: ");     //prompt user for radius of circle
    scanf("%lf", &r);                       //store in var r
    
    area = r * r * PI;      //calculate area
    
    printf("The area of the circle with radius %lf is %lf\n", r, area);     //print resulting area
    return (EXIT_SUCCESS);
}

