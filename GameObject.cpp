// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "GameObject.h"

using namespace std;


GameObject :: GameObject(char in_code)
    // initialize the display_code to in_code,
    // initialize id_num to 1,
    // initialize state to 0,
    // outputs the message: "GameObject constructed"
: display_code(in_code), id_num(1), state(0) {
    cout << "GameObject constructed" << endl;    
}

GameObject :: GameObject(Point2D in_loc, int in_id, char in_code)
    // initialize the display_code, id_num, and location,
    // initialize state to 0,
    // outputs the message: "GameObject constructed"
: display_code(in_code), id_num(in_id), location(in_loc), state(0) {
    cout << "GameObject constructed" << endl;
}

Point2D GameObject :: GetLocation() {
    // returns the location of the object
    return location;
}

int GameObject :: GetId() {
    // returns the id of the object
    return id_num;
}

char GameObject :: GetState() {
    // returns the state of the object
    return state;
}

void GameObject :: ShowStatus() {
    // outputs "(display_code)(id_num) at (location)""
    cout << "(" << display_code << ")(" << GetId() << " at (" << GetLocation() << ")" << endl;
    return;
}