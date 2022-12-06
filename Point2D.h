// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include <string>
#include "Vector2D.h"

using namespace std;


// prototyped
#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
    // >> public members <<
    public:
        double x;   // x value of the point for cartesian coordinates
        double y;   // y value of the point for cartesian coordinates

        // >> constructors <<
        Point2D(); // default constructor
        Point2D(double in_x, double in_y);
//        ~Point2D();     // usually, do not need destructor; however, it makes a linkage error
};

// >> non-member functions <<
double GetDistanceBetween (Point2D p1, Point2D p2);

// >> non-member overloaded operators <<
Point2D operator + (Point2D p1, Vector2D v1);
Vector2D operator - (Point2D p1, Vector2D p2);
ostream& operator << (ostream& out, Point2D p1);


#endif