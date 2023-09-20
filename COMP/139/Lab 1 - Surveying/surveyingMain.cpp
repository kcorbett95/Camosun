/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: C0527059
 *
 * Created on September 13, 2023, 2:35 PM
 */

#include "CPP Header.h"
#include "surveyingHeader.h"
#define PI M_PI
using namespace std;

int main(int argc, char *argv[]) {

    //Declare variables
    double radius, pegDist, space, nSpaces, B, b, theta, thetadeg;
    int nLights, intSpaces;
    //Get user input
    getUserInput(radius, pegDist, space);

    //compute number of lights required
    B = (2 * asin(pegDist / (2 * radius))); //Angle between pegs in rads
    b = (PI - B) / 2; //Angle between Chord and origin in rads
    //theta = space/radius;    
   
    nSpaces = ceil((radius * B) / space); //Number of spaces between lights    
    nLights = nSpaces + 1; //Number of lights needed
    intSpaces = nSpaces; //Number of spaces cast to int
    theta = B / intSpaces; //Angle between lights in rads
    //    cout << "DEBUG:" << endl;
    //    cout << "angle B: " << B << endl;
    //    cout << "angle b: " << b << endl;
    //    cout << "angle theta: " << theta << endl;
    //    cout << "nSpaces: " << nSpaces << endl;
    //    cout << "nLights: " << nLights << endl;

    //Allocate arrays for angles and distances
    double angles[nLights], distances[nLights];

    //compute angles
    angles[0] = 0;
    for (int i = 0; i < nLights; i++) {
        angles[i + 1] = ((PI - ((i + 1) * theta)) / 2) - b;
        //cout << "DEBUG angle[" << i + 1 << "]: " << angles[i + 1]*(180 / PI) << endl;
    }
    //Compute Distances
    distances[0] = 0;
    for (int i = 0; i < nLights; i++) {
        distances[i+1] = 2*(radius*(sin((i+1)*(theta)/2)));
        //cout << "DEBUG dist[" << i + 1 << "]: " << distances[i + 1] << endl;
    }
    //output results
    outputResults(angles, distances, nLights);

    return 0;
}

/*
 * Prints the result to standard output - command-line interface
 *
 * @param angles Array of angles, referenced to the baseline chord (radians)
 * @param distances Array of distances to the streetlights
 * @param numLights Number of streetlights
 *
 */
void outputResults(const double angles[], const double distances[], const int numLights) {
    cout << numLights << " streetlights are required." << endl;

    for (int i = 0; i < numLights; i++) {
        cout << "Light " << (i + 1) << ": Distance=" << distances[i];
        if (distances[i] > 1.0e-6) {
            double angle = (abs(angles[i]) < 1.0e-6) ? 0.0 : angles[i];
            cout << " Angle=" << angle * 180.0 / M_PI << " degrees";
        }
        cout << endl;
    }
}

/**
 * Gets input values from the user via a command-line prompt:
 * radius of curvature, distance between pegs, and maximum streetlight spacing
 *
 * @param radius Reference to the radius of curvature
 * @param pegDist Reference to the distance between arc endpoints
 * @param spacing Reference to maximum streetlight spacing
 * 
 */
void getUserInput(double &radius, double &pegDist, double &spacing) {
    cout << "Enter the radius of curvature: ";
    cin >> radius;
    cout << "Enter the distance between the survey pegs at the endpoints: ";
    cin >> pegDist;
    if (pegDist > 2.0 * radius) {
        cerr << "The distance between pegs cannot be more than twice the radius!";
        exit(EXIT_FAILURE);
    }
    cout << "Enter the maximum streetlight spacing along the arc: ";
    cin >> spacing;
}
