// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Building.h"

using namespace std;


Building :: Building ()    // default constructor
    // initialize display_code to 'B'
{
    display_code = 'B';
}

Building :: Building (char in_code, int in_Id, Point2D in_loc) {
    // initialize id number to in_Id
    id_num = in_Id;

    // initialize location to in_loc
    location = in_loc;

    // initialize display_code to in_code
    display_code = in_code;
}

void Building :: AddOneTrainer () {
    // increments trainer_count by one
    trainer_count++;
    return;
}

void Building :: RemoveOneTrainer () {
    // decrements trainer_count by one
    trainer_count--;
    return;
}

void Building :: ShowStatus () {
    // prints "(display_code)(id) located at (location)"
    cout << "(" << display_code << ")(" << GetId() << " at (" << GetLocation() << ")" << endl;

    // prints "(trainer_count) trainers is/are in this building"
    cout << "(" << trainer_count << ") trainers is/are in this building" << endl;
    return;
}

bool Building :: ShouldBeVisible () {
    // returns true because buildings are always visible
    return true;
}