/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: c0527059
 *
 * Created on October 4, 2023, 2:52 PM
 */

#include <cstdlib>
#include "CPP Header.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc < 3) {
        cout << "Invalid number of arguments, exit";
    }

    ifstream input(argv[1]);
    ofstream output(argv[2], fstream::app);

    if (input.fail()) {
        cout << "Input file does not exist" << endl;
        return -1;
    } else {
        //read data
        string word;
        char c;
        while (input.eof() == false) { //read until end of file
            input.get(c); //get first char 
//            input.putback(c); //put first char back
//            cin >> ws; //remove leading whitespace
            int c = input.peek();
            if (isdigit(c)) { //determine if number or word
                int n;
                input >> n;
                output << "Found int: " << n << endl;
            } else {
                //input.putback(c);
                input >> word;
                output << "Found a " << word.length() << " character word: " << word << endl;
            }
        }
        input.close();
        output.close();
    }

    return 0;
}

