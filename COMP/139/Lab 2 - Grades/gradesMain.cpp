/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: c0527059
 *
 * Created on September 20, 2023, 2:37 PM
 */

#include "CPP Header.h"

using namespace std;
/**
 * A reusable function for getting validated in-range numbers.
 * Repeatedly asks for the value if an out-of-range number gets entered
 *
 * @param prompt A string such as "Enter the mark"
 * @param number A pointer to the number we are trying to read
 * @param min The minimum permissible value
 * @param max The maximum permissible value  
 *
 * @return true if the input contains only numeric characters, false otherwise
 */
bool getValidNumber(string prompt, double *value, const double min, const double max);
string gradeFromMark(const double mark);

/*
 * 
 */
int main(int argc, char *argv) {

    //declare variables

    double tempMark = 0, mark = 0, weight = 0, markFinal = 0, weightTotal = 0;
    double* markPtr = &mark;
    double* weightPtr = &weight;
    cout << "This program computes a letter grade from a weighted sum of marks" << endl;
    cout << "For marks, minimum allowable value is 0, maximum is 100" << endl;
    cout << "For weights, minimum allowable value is 1, maximum is 50" << endl;
    cout << "The weights must total 100%" << endl;
    cout << "Enter a non-number (such as 'q') to terminate your list of marks" << endl;

    while (true) {
        if (getValidNumber("Enter a mark in percent: ", markPtr, 0, 100)) {
            if (getValidNumber("Enter the weight: ", weightPtr, 1, 50)) {
                weightTotal = weightTotal + *weightPtr;
//                cout << "**DEBUG** weightPtr = " << *weightPtr << endl;
//                cout << "**DEBUG** weightTotal = " << weightTotal << endl;
                if (weightTotal > 100) {
                    cout << "Invalid weight, total greater than 100, try again" << endl;

                    return 1;
                }
            }
            tempMark = (*weightPtr / 100) * (*markPtr);
            markFinal = markFinal + tempMark;
//            cout << "**DEBUG** weightPtr = " << *weightPtr << endl;
//            cout << "**DEBUG** markPtr = " << *markPtr << endl;
//            cout << "**DEBUG** tempMark = " << tempMark << endl;
//            cout << "**DEBUG** markFinal = " << markFinal << endl;
        } else break;
    }

    //output results
    cout << "Mark is " << markFinal << ", grade is " << gradeFromMark(markFinal);
    return 0;
}

string gradeFromMark(const double mark) {
    if (mark >= 90) {
        return "A+";
    } else if ((90 > mark) && (mark >= 85)) {
        return "A";
    } else if ((85 > mark) && (mark >= 80)) {
        return "A-";
    } else if ((80 > mark) && (mark >= 77)) {
        return "B+";
    } else if ((77 > mark) && (mark >= 73)) {
        return "B";
    } else if ((73 > mark) && (mark >= 70)) {
        return "B-";
    } else if ((70 > mark) && (mark >= 65)) {
        return "C+";
    } else if ((65 > mark) && (mark >= 60)) {
        return "C";
    } else if ((60 > mark) && (mark >= 50)) {
        return "D";
    } else if (50 > mark) {
        return "F";
    }//else {
     //   return "NULL";
    }


bool getValidNumber(string prompt, double *value, const double min, const double max) {
    while (true) {
        double temp = 0;
        cout << prompt;
        cin >> temp; // This needs to be the numeric variable, NOT its address
        if (cin.good() == false) { // Invalid Input (not a number in this case)
            cin.clear(); // Clear the error flags
            cin.ignore(255, '\n'); // Throw away the line of input
            cout << "Input terminated" << endl;
            return false;
        }
        if (temp > max) {
            cout << "Value too large, invalid" << endl;
            cin.clear(); // Clear the error flags
            cin.ignore(255, '\n'); // Throw away the line of input

        } else if (temp < min) {
            cout << "Value too small, invalid" << endl;
            cin.clear(); // Clear the error flags
            cin.ignore(255, '\n'); // Throw away the line of input

        } else {
            *value = temp;
            break;

            
        }
    }return true;
}

