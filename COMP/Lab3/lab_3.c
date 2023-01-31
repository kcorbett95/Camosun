
/* 
 * File:   Lab_3.c
 * Author: C0527059
 *
 * Compute acceleration, velocity, and displacement over time
 * 
 * Created on January 31, 2023, 8:42 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define g 9.80665  //Gravitational constant

//declare functions
double UserInput();
double density(double);
/*
 * 
 */
int main(void) {

    //declare variables
    double height, mass, drag, area, time_step, time, V, A, d, Fg, Fd, Fnet;
    
    //Prompt user for  inputs
    printf("\nEnter drop height in metres: ");
    height = UserInput();
    printf("\nEnter mass in kg: ");
    mass = UserInput();
    printf("\nEnter Drag Coefficient: ");
    drag = UserInput();
    printf("\nEnter Cross-Sectional Area: ");
    area = UserInput();
    printf("\nEnter time-step size: ");
    time_step = UserInput();
    
    time, V=0, A = 0;   //set initial time, velocity, accel
    //table heading
    printf("Time   Height   Velocity\n");  
    
    //for loop to run 100k calculations
    for(int i=0; i<10; i++){
        
        //increment Velocity, Accel, and time based on time step
        time = time_step*i;
        //print values
        
        
        //Calculate variables
        d = density(height);
        Fg = mass*g;
        Fd = -0.5*drag*d*area*(V*V);
        Fnet = Fg + Fd;
        A = Fnet/mass;      //solve for acceleration A
        
        V = V + A*time_step;
        height = height - (V * time_step);
        printf("%.2f   %.1f   %.2f\n", time, height, V);
       
    }
    
    return (EXIT_SUCCESS);
}

double UserInput(void){
    //takes a user input and returns it... I don't want 1,000 scanf()'s in main lol
    double a;
    scanf("%lf", &a);
    return (a);
}

/*  Author: Dale Shpak
 * Compute the density of dry air in SI units.
 * (Uses the global gravitational constant g).
 *
 * @param altitude Altitude in metres above mean sea level
 *
 * @return Density in SI units
 */
double density(double altitude) {
  const double p0 = 101.325e3; // Sea-level std atmospheric pressure, Pascals
  const double T0 = 288.15;    // Sea-level std temperature, Kelvins
  const double L  = 0.0065;    // Temperature lapse rate, K/m
  const double R  = 8.31447;   // Ideal gas constant, J/(mol.K)
  const double M  = 0.0289644; // Molar mass of dry air, kg/mol
  double p, T;
  T = T0 - L*altitude;
  p = p0 * pow((1 - (L*altitude)/T0), (g*M)/(R*L)); //Presure at altitude
  return p*M/(R*T); //return density
}