// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "GameObject.h"

using namespace std;


// prototyped
#ifndef BUILDING_H
#define BUILDING_H

class Building : public GameObject {
    // inherits from GameObject (base class)
    // responsible for tracking the total number of Pokemon Trainers that enter or leave a building

    // >> public members <<
    private:
        unsigned int trainer_count;  // number of trainers currently within the building

    // >> public members <<
    public:
        Building();
        Building(char in_code, int in_id, Point2D in_loc);
        // virtual ~Building();
        void AddOneTrainer();
        void RemoveOneTrainer();
        void ShowStatus();
        bool ShouldBeVisible();
};


#endif