/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   Lab_2.c
 * Author: C0527059 Kevin Corbett
 * 
 * Take user temperature input, validates input, determine units and convert to all other units of temperature
 *
 * Created on January 24, 2023, 8:35 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <string.h>

int main(void) {
    //declare variables
    float temp;
    char unitstr[10], unit;
    
    //prompt user for input
    printf("Please enter a temperature with units F, C, or K: ");
    
    //validate user input types with if() statement, only runs if types are correct (number, then char)
    if(scanf(" %f%10s", &temp, unitstr) != 0)
    {   //capitalize unit input, take first char from input buffer string
        unit = toupper(unitstr[0]);     
        //printf("******DEBUG******* temp = %f, unitstr = %10s, unit = %c\n", temp, unitstr, unit);
        
        //Validate inputs: invalid if units are anything other than C, F, or K
        if(unit!='C'&&unit!='F'&&unit!='K')     
        {
            printf("%c is not a valid unit\n", unit);
        } 
        else if(unit=='K'&&temp<0)      //Validate input: negative kelvin does not exist
        {
            printf("You can't have negative Kelvin silly\n");
        }
        else        //Temp conversion runs after validating inputs
        {
            switch(unit)    //run different calculations based on input units
            {
                case 'C' :
                    //printf("******DEBUG******* it thinks it's C\n");
                    printf("%.3fC = %.3fF = %.3fK", temp, ((temp*1.8)+32), (temp+273.15));
                    break;
            
                case 'F' :
                    //printf("******DEBUG******* it thinks it's F\n");
                    printf("%.3fF = %.3fC = %.3fK", temp, ((temp-32)/1.8), ((temp+459.7)*5/9));
                    break;
                
                case 'K' :
                    //printf("******DEBUG******* it thinks it's K\n");
                    printf("%.3fK = %.3fF = %.3fC", temp, (((temp-273.15)*1.8)+32), (temp-273.15));  
                    break;
            }
        }
    }
    else        //if the input types do not match the validation in the first if statement, the scanf() returns zero and moves here
    {
        printf("Invalid input types\n");
        //printf("******DEBUG******* temp = %f, unit = %c\n", temp, unit);
    }
    return (EXIT_SUCCESS);
}

