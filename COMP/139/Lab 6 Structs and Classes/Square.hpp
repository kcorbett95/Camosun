/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Square.hpp
 * Author: c0527059
 *
 * Created on November 1, 2023, 2:38 PM
 */

#ifndef SQUARE_HPP
#define SQUARE_HPP
//#include "Shape.hpp"
#include "Rectangle.hpp"

class Square : public Rectangle {
private:
    //double slength;
protected:
    void printMe(std::ostream& os) const override;  // Implicitly virtual because of Shape's declaration
public:
    /**
     * This constructor passes the x location to the base class constructor
     * in Shape and also initializes the Square's size.
     *
     * We choose to make this an inline function.
     *
     * @param l Length
     * @param xLoc Initial x coordinate
     * @param yLoc Initial y coordinate
     */
    Square(double l, int x, int y) : Rectangle(l, l, x, y){
    }

//    double getLength(void) const {
//        return length;
//    }

    /**
     * The Square "draws" itself at its current location
     */
    void draw() const override;  // Implicitly virtual because of Shape's declaration
};

#endif /* SQUARE_HPP */

