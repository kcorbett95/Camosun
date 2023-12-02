#include "PID_Controller.hpp"

// Implementation of controlStep()
double PID_Controller::controlStep (const double plantOutput, double setpoint) {
    //initializa variables
    double error = 0;
    double controlOutput = 0;
    double Dout = 0;
    double Iout = 0;
    double Pout = 0;
    double Q = 0;
       
    error = setpoint - plantOutput; //error calc
    Pout = error;   //proportional output
    Q = (0.9*prevQ) + (0.1*error);  //Q for integral output
    Iout = Q / kI;  //integral output
    Dout = kD * (plantOutput - prevOutput); //derivative output
    prevQ = Q;  //iterate Q for next control step
    prevOutput = plantOutput;   //iterate prevOutput for next control step
    controlOutput = Pout + Iout - Dout;     //output control correction
    
    return setpoint + kP*controlOutput;     //apply control correction
}