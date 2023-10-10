#include "PID_Controller.hpp"

// Implementation of controlStep()
double PID_Controller::controlStep (const double plantOutput, double setpoint) {
    
    double error = 0;
    double controlOutput = 0;
    double Dout = 0;
    double Iout = 0;
    double Pout = 0;
    
    error = setpoint - plantOutput;
    
    return setpoint + controlOutput;
}