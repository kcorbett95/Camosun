/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* Program to prompt user for purchase price and amount tendered and output 
 * total change due in number and type of bills and change, rounded to nearest 
 * $0.05
 * File:   changeItem.c
 * Author: Kevin Corbett
 *         C0527059
 * Created on January 10, 2023, 9:14 a.m.
 */

#include "changeItem.h"

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

double changeItem(double change, const double price, const char *singleName, const char *pluralName, const double value) {

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