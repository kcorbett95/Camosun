/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* Program to prompt user for purchase price and amount tendered and output 
 * total change due in number and type of bills and change, rounded to nearest 
 * $0.05
 * File:   main.c
 * Author: Kevin Corbett
 *         C0527059
 * Created on January 10, 2023, 9:14 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include "c166.h"
#define N_VALUES 8

//Declaring functions
//double UserInput(const char *);
double MakeChange(double payment, const double price, const char *singleName, const char *pluralName, const double value);

int main(void) {

    //Declare variables
    double price, payment, change, round;
    double value[N_VALUES] = {20, 10, 5, 2, 1, 0.25, 0.1, 0.05}; //array of denomination values
    char *singleName[N_VALUES] = {"twenty", "Ten", "Five", "Toonie", "Loonie", "Quarter", "Dime", "Nickel"};
    char *pluralName[N_VALUES] = {"twenties", "Tens", "Fives", "Toonies", "Loonies", "Quarters", "Dimes", "Nickels"};


    //prompt user for price input
    price = UserInput("Enter price: "); //user input function 
    //printf("******debug price = %lf******\n", price);
    
    //error handling
    if (price < 0) {
        printf("Price must be positive");
        return;
    }
    
    //prompt user for payment input
    payment = UserInput("Enter payment: "); //user input function 
    //printf("******debug payment = %lf******\n", payment);

    //math to round to nearest nickel
    change = payment - price;

    //check if payment is sufficient or exact change, error handling
    if (change < 0) {
        printf("Insufficient Funds, $%.2f owed\n", change*-1);
        return;
    }if (change == 0) {
        printf("Exact Change\n");
        return;
    }
    //print results, calc change due
    printf("Change due is: $%.2f\n", change);
    change = floor(change * 20 + 0.5) / 20;     //multiply by 20 and add 0.5, round down, and divide result by 20 to get nearest 0.05
    printf("Rounded to nearest nickel: $%.2f\n", change);

    for (int k = 0; k < N_VALUES; k++) {

        //printf("******debug denom value = %.2f******\n", value[k]);    
        change = MakeChange(change, price, singleName[k], pluralName[k], value[k]);

    }
    return (EXIT_SUCCESS);
}

double UserInput(const char *message) {
    //takes a user input and returns it... I don't want 1,000 scanf()'s in main lol
    double a;
    int loop=1;
    while (loop) {
            printf("%s", message);
            if (scanf("%lf", &a) != 1) {
                printf("Input Error, please try again\n");
                loop = 1;
            }
            else
            {
                loop=0;
            }
        }
    return (a);
}

double MakeChange(double change, const double price, const char *singleName, const char *pluralName, const double value) {

    //declaring variables
    int numbills;

    numbills = change / value; //get number of bills from value array
    if (numbills > 1) {
        printf("%dx %s \n", numbills, pluralName); //print number of plural bills due
    } else if (numbills == 1) {
        printf("%dx %s \n", numbills, singleName); //print number of singular bills due
    }

    change = change - (numbills * value); //subtract value of bills from change due
    //printf("******debug remain %.2f******\n", change);

    return (change);
}
