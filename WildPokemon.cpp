// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// December 12, 2022

/*
 * "instruction" is the steps given on the assignments.
 * clarified it to organize and show difference between steps from the assignments and comment from myself
 */

// required header-file
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>   // generate random variables using time
#include "Trainer.h"

using namespace std;


// prototyped
#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H

class WildPokemon {
    // >> protected members <<
    protected:
        double attack;
        double health;
        bool variant;
        bool in_combat;
        string name;
        Trainer* current_trainer;

    // >> public members <<
    public:
        WildPokemon
};