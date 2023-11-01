/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Square.hpp"
#include "Rectangle.hpp"

/**
 * The draw() member function
 */
void Square::draw() const {
    std::cout << "Square of size [" << getLength() << "] drawn at " << getX() << " " << getY() << std::endl;
}

void Square::printMe(std::ostream& os) const {
    os << "Square of size [" << getLength() << "] at " << getX() << " " << getY();
}