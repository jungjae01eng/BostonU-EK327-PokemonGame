// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;


Point2D :: Point2D ()   // default constructor
    // initializes x and y to 0.0
: x(0.0), y(0.0) {

}

Point2D :: Point2D (double in_x, double in_y)
    // sets x and y to in_x and in_y
: x(in_x), y(in_y) {

}

//Point2D :: ~Point2D() {
//    // destructor
//    cout << "Point2D destructed!" << endl;
//}

double GetDistanceBetween (Point2D p1, Point2D p2) {
    // returns the cartesian distance between p1 and p2
    double delta_x;
    double delta_y;
    double x_pow;
    double y_pow;

    delta_x = (p2.x - p1.x);    // change in x
    delta_y = (p2.y - p1.y);    // change in y
    x_pow = pow(delta_x, 2);    // x power of 2
    y_pow = pow(delta_y, 2);    // y power of 2

    return (sqrt(x_pow + y_pow));
}

Point2D operator + (Point2D p1, Vector2D v1) {
    // overloaded operator: add p1 and v1
    double x;
    double y;

    x = p1.x + v1.x;
    y = p1.y + v1.y;

    Point2D p_new;
    p_new.x = x;
    p_new.y = y;

    return p_new;
}

Vector2D operator - (Point2D p1, Point2D p2) {
    // overloaded operator: subtract p1 and p2
    double x;
    double y;

    x = p1.x - p2.x;
    y = p1.y - p2.y;

    Vector2D v_new;
    v_new.x = x;
    v_new.y = y;

    return v_new;
}

ostream& operator << (ostream& out, Point2D p1) {
    // overloaded operator: return output formatted as (x, y)
    out << "(" << p1.x << ", " << p1.y << ")";

    return out;
}