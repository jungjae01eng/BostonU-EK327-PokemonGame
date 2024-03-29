// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


// prototyped
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
    // >> public members <<
    public:
        double x;       // x displacement value of the vector
        double y;       // y displacement value of the vector

        // >> constructors <<
        Vector2D ();    // default constructor
        Vector2D (double in_x, double in_y);
};

// >> non-member overloaded operators <<
Vector2D operator * (Vector2D v1, double d);
Vector2D operator / (Vector2D v1, double d);
ostream& operator << (ostream& out, Vector2D v1);


#endif