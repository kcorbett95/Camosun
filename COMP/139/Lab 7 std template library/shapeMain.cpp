/*
 * A main() to demonstrate inheritance, polymorphism, virtual functions,
 * and an abstract class.
 * Uses classes: Shape, Rectangle, and Circle.
 * 
 * File:   shapeMain.cpp
 * Author: dale
 *
 * Created on November 7, 2011, 2:27 PM
 */

#include <iostream>
#include <cstdlib>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "StackGiven.hpp"

int main(int argc, char* argv[]) {
    const int N_SHAPES = 4;
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Square s1(5,5,3);
    // Can't instantiate an object from Shape class because it is abstract
    // Shape s1(1, 2);  yields a compiler error

    /* Create an array of pointers to Shapes.
     * Since Shape is the base class, we can point to any derived object,
     * i.e., Shape is polymorphic
     */
//    Shape *shapes[N_SHAPES];
//    shapes[0] = &c1;
//    shapes[1] = &r1;
//    shapes[2] = &c2;
//    shapes[3] = &s1;
//
    c1.moveTo(27, 36);         // move the first circle
    c2.moveTo(17, 4);  // this will move the second circle

    Stack<Shape*> ShapeStack;
    ShapeStack.push(&c1);
    ShapeStack.push(&c2);
    ShapeStack.push(&r1);
    ShapeStack.push(&s1);
    
    /* Draw all of the Shapes.
     * Since draw() is a virtual function, binding to draw() will be
     * done at run-time, resulting in the correct draw() for each Shape
     */
    while(!ShapeStack.isEmpty()){
        try{
        ShapeStack.pop()->draw();   //draw shapes
        ShapeStack.top();   //try to throw exception after popping last shape
        }
        catch(const StackException& issue){
            std::cout << issue.what() << std::endl;   //output what the issue is
        }
    }
    //for (int i = 0; i < N_SHAPES; i++) {
      // Each shape knows how to draw itself
      //shapes[i]->draw();
      // Each shape knows how to print itself using printMe
      // which was overloaded to get polymorphism from the
      // Non-member function <<
      //std::cout << *shapes[i] << std::endl;
    //}

    return EXIT_SUCCESS;
}

