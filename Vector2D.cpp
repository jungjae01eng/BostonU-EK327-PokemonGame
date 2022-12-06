// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;


Vector2D :: Vector2D ()   // default constructor
    // initializes x and y to 0.0
: x(0.0), y(0.0) {

}

Vector2D :: Vector2D (double in_x, double in_y)
    // sets x and y to in_x and in_y
: x(in_x), y(in_y) {

}

Vector2D operator * (Vector2D v1, double d) {
    // overloaded operator: multiply v1 and d
    // assume v1 represents Vector2D, d represents double
    double x;
    double y;

    x = v1.x * d;
    y = v1.y * d;

    Vector2D v_new;
    v_new.x = x;
    v_new.y = y;

    return v_new;
}

Vector2D operator / (Vector2D v1, double d) {
    // overloaded operator: divide d from v1
    double x;
    double y;

    x = v1.x / d;
    y = v1.y / d;

    Vector2D v_new;

    // if dividing by zero, it should just create v1
    if (d == 0) { 
        v_new.x = v1.x;
        v_new.y = v1.y;
    }

    v_new.x = x;
    v_new.y = y;

    return v_new;
}

ostream& operator << (ostream& out, Vector2D v1) {
    // overloaded operator: return output formatted as <x, y>
    out << "<" << v1.x << ", " << v1.y << ">";

    return out;
}