/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* Program to prompt user for purchase price and amount tendered and output 
 * total change due in number and type of bills and change, rounded to nearest 
 * $0.05
 * File:   MakeChange.c
 * Author: Kevin Corbett
 *         C0527059
 * Created on January 10, 2023, 9:14 a.m.
 */

#include "changeItem.h"

#define N_VALUES 8

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
    
    //error handling
    if (payment < 0) {
        printf("Payment must be positive");
        return;
    }
    
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
    
    //for loop to run through different denominations
    for (int k = 0; k < N_VALUES; k++) {

        //printf("******debug denom value = %.2f******\n", value[k]);    
        change = changeItem(change, price, singleName[k], pluralName[k], value[k]);

    }
    return (EXIT_SUCCESS);
}


