// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Building.h"

using namespace std;


Building :: Building ()     // default constructor
         : GameObject('T') {
    // initialize display_code to 'B'
    display_code = 'B';

    // instruction_2: print the message
    cout << "Building default constructed!" << endl;
}

Building :: Building (char in_code, int in_id, Point2D in_loc)
         : GameObject(in_loc, in_id, in_code) {
    // instruction_1: initialize id number to in_Id
    id_num = in_id;

    // instruction_1: initialize location to in_loc
    location = in_loc;

    // instruction_1: initialize display_code to in_code
    display_code = in_code;

    // instruction_2: print the message
    cout << "Building constructed!" << endl;
}

void Building :: AddOneTrainer () {
    // instruction_1: increments trainer_count by one
    trainer_count++;
    return;
}

void Building :: RemoveOneTrainer () {
    // instruction_1: decrements trainer_count by one
    trainer_count--;
    return;
}

void Building :: ShowStatus () {
    // instruction_1: prints "(display_code)(id) located at (location)."
    cout << display_code << GetId() << " at " << GetLocation() << "." << endl;

    // instruction_2: prints "(trainer_count) trainers is/are in this building."
    cout << trainer_count << " trainers is/are in this building." << endl;
    return;
}

bool Building :: ShouldBeVisible () {
    // instruction_1: returns true because buildings are always visible
    return true;
}