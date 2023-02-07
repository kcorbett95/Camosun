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
#include <math.h>

//Declaring functions
double UserInput(const char *);      
//double MakeChange(double payment, const double price, const char *singleName, const char *pluralName);

int main(void) {
    
    float price, payment;      //Declare variables
    
    printf("debug 1");        //prompt user for price input
    UserInput('Enter price: ');            //user input function 
    printf("******debug price = %lf******\n", price);
    printf("Enter payment: ");      //prompt user for payment input
    //payment = UserInput();          //user input function 
    //printf("******debug payment = %lf******\n", payment);
    //MakeChange(payment, price);     //call MakeChange function to clean up main()
    
    return (EXIT_SUCCESS);
}

double UserInput(const char *message){
    //takes a user input and returns it... I don't want 1,000 scanf()'s in main lol
    double a;
    printf("%s", *message);
    scanf("%lf", &a);
    return (a);
}

//float MakeChange(double paymente, const double price, const char *singleName, const char *pluralName){
//    
//    //declaring variables
//    double change, round;
//    int numbills;
//    double value[8] = {20,10,5,2,1,.25,0.1,0.05};    //array of denomination values
//    
//    //math to round to nearest nickel
//    change = payment - price;     //take arguments from main()
//    round = floor(change * 20 + 0.5) / 20;      //multiply by 20 and add 0.5, round down, and divide result by 20 to get nearest 0.05
//    
//    //check if payment is sufficient or exact change
//        if(change<0){
//            printf("Insufficient Funds\n");
//            return;
//        }
//        else if(change==0){
//            printf("Exact Change\n");
//            return;
//        }
//    
//    //print results
//    printf("Change due is: $%.2f\n", change);
//    printf("Rounded to nearest nickel: %.2f\n", round);
//    
//    //for loop to break change into denominations 
//    //more efficient than writing out individual code for each denomination lol
//    for(int k=0; k<8; k++){
//        
//        //printf("******debug denom value = %.2f******\n", value[k]);
//        numbills = round/value[k];                      //get number of bills from value array
//        printf("%dx \$%.2f \n", numbills, value[k]);    //print number of bills due
//        round = round - (numbills*value[k]);            //subtract value of bills from change due
//        //printf("******debug remain %.2f******\n", round);
//        
//    }
//        
//    return;
//}
