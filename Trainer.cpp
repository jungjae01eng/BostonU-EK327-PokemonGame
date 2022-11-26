// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required headerfile
#include <iostream>
#include <cmath>
#include "Trainer.h"

using namespace std;


Trainer :: Trainer() {
    // initialize the speed to 5 and outputs a message: "Trainer default constructed."
    speed = 5;
    cout << "Trainer default constructed." << endl;
}

Trainer :: Trainer(char in_code) {
    // initialize the speed to 5 and outputs a message: "Trainer constructed."
    // initialize State = STOPPED
    // initialize Display_code = in_code
    speed = 5;
    cout << "Trainer constructed." << endl;
    state = STOPPED;
    display_code = in_code;
}

Trainer :: Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) {
    // initialize the speed to in_speed and sets name to in_name
    // outputs a message: "Trainer constructed"
    speed = in_speed;
    name = in_name;
    cout << "Trainer constructed." << endl;
}

void Trainer :: StartMoving(Point2D dest) {
    // tells the trainer to start moving
    // calls the setup_destination() function
    // sets the state to MOVING
    // if the trainer is already at the destination print "(display_code)(id): I'm already there. See?"
    // if the trainer is infected print "(display_code)(id): My pokemon have fainted. I may move but you cannot see me."
    // otherwise prints "(display_code)(id): On my way."

    void SetUpDestination(Point2D dest);    // call the set
    state = MOVING;

    // if (location == dest) {

    // }


}

void Trainer :: StartMovingToGym(PokemonGym* gym) {
    //
}

void Trainer :: StartMovingToCenter(PokemonCenter* center) {
    //
}

void Trainer :: StartBattling(unsigned int num_battles) {
    //
}

void Trainer :: StartRecoveringHealth(unsigned int num_potions) {
    //
}

void Trainer :: Stop() {
    // tells trainer to stop doing whatever it was doing
    // sets the state to STOPPED
    // prints "(display_code)(id): Stopping.."
    

    state = STOPPED;
    cout << "(" << display_code << ")(" << id_num << "): Stopping" << endl;
}

bool Trainer :: HasFainted() {
    // returns true if health is 0
    if (health == 0) {
        return true;
    } else {
        return false;
    }
}

bool Trainer :: ShouldBeVisible() {
    // return true if the trainer is not fainted
    if (HasFainted() == true) {
        return false;
    } else {
        return true;
    }
}

void Trainer :: ShowStatus() {
    // prints "(name) status: "
    // call GameObject::ShowStatus()
    
}

bool Trainer :: Update() {
    //
    
}

bool Trainer :: UpdateLocation() {
    //
}

void Trainer :: SetupDestination(Point2D dest) {
    // set up the object to start moving to dest
    // calculate delta
    // find the dest - location using Point2D opeartor -
    double difference;
    // difference = Vector2D operator - (dest, location);
    // delta = difference * (speed/GetDistanceBetween(dest, location));

}