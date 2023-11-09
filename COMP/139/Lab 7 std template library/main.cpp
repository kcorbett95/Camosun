/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: c0527059
 *
 * Created on November 8, 2023, 2:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<Shape*> shapes; //create shapes vector    
    //create shapes
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Square s1(5, 5, 3);
    Square s2(3, 3, 9);

    //store shapes in vector
    try {
        shapes.push_back(&c1);
        shapes.push_back(&r1);
        shapes.push_back(&c2);
        shapes.push_back(&s1);
    } catch (const out_of_range& e) {
        std::cout << e.what() << std::endl; //output what the issue is
    }
   
    //create shape iterator
    vector<Shape*>::iterator shapeIT;
    try {
        shapeIT = shapes.begin();
    } catch (const out_of_range& e) {
        std::cout << e.what() << std::endl; //output what the issue is
    }
     //[], front, back, size, capacity, insert, pop_back, at, max_size.
    try{
        cout << "Address of 3rd shape from middle of list: " << shapes[2] << endl;   //output element within list without moving order
        cout << "First element is: " << *shapes.front() << endl; //output front of list
        cout << "Last element is: " << *shapes.back() << endl;   //output back of list
        cout << "Size of list is: " << shapes.size() << endl;   //output size of list
        cout << "Capacity of list is: " << shapes.capacity() << endl;   //output capacity
        cout << "Inserted \"" << s2 <<"\" in position 2" << endl;  //insert method
        shapes.insert(shapeIT+2,&s2);
        shapes.pop_back();
        cout << "Last element in list deleted" << endl;   //pop_back method
        cout << "Value of shape at position 2 is: " << *shapes.at(2) << endl;    //at method
        cout << "Max size of vector is: " << shapes.max_size() << endl;     //max size method
        cout << "Out of range test, trying to view 8th element" << endl;
        cout << *shapes.at(8);
        
        
    }catch (const out_of_range& e) {
        std::cout << e.what() << std::endl; //output what the issue is
    }
    cout << "printing list in order:" << endl << endl;
    for (shapeIT = shapes.begin(); shapeIT != shapes.end(); shapeIT++) {
        try {
            (*shapeIT)->draw();
        } catch (const out_of_range& e) {
            std::cout << e.what() << std::endl; //output what the issue is
        }
    }


return 0;
}

