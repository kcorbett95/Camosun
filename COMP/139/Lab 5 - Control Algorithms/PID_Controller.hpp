/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PID_Controller.hpp
 * Author: c0527059
 *
 * Created on October 10, 2023, 4:02 p.m.
 */

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

class PID_Controller : public Controller {
private:
    const double kP; // The proportional gain
    const double kD; //Derivative gain
    const double kI; //Integral gain
public:

    PID_Controller(const double Pgain, const double Dgain, const double Igain) : kP(Pgain), kD(Dgain), kI(Igain) {
    };

    // Our promise to implement the function from the abstract base class
    double controlStep(double plantOutput, double setpoint);
};

#endif /* PID_CONTROLLER_HPP */

