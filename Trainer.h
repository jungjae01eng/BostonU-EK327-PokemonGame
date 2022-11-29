// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>   // generate random variables using time
#include <string>

#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

using namespace std;


// prototyped
#ifndef TRAINER_H
#define TRAINER_H

class Trainer : public GameObject {
    // inherits from GameObject
    enum TrainerStates {
        STOPPED = 0,
        MOVING = 1,
        FAINTED = 2,
        AT_CENTER = 3,
        IN_GYM = 4,
        MOVING_TO_CENTER = 5,
        MOVING_TO_GYM = 6,
        BATTLING_IN_GYM = 7,
        RECOVERING_HEALTH = 8
    };

    private:
        double speed;       // speed the object travels, expressed as distance per update ime unit
        bool is_at_center;  // true if the Trainer is in a PokemonCenter
        bool is_IN_GYM;     // true if the Trainer is in a PokemonGym
        unsigned int health = 20;
        unsigned int experience = 0;
        double PokeDollars = 0;
        unsigned int battles_to_buy = 0;    // stores the number of battles to buy when in a PokemonGym
        unsigned int potions_to_buy = 0;    // stores the number of potions to buy when in a PokemonCenter
        string name;        // Name of the Trainer
        PokemonCenter* current_center = 0;  // a pointer to the current PokemonCenter
        PokemonGym* current_gym = 0;        // a pointer to the current PokemonGym
        Point2D destination;        // the object's current destination coordinates in the real plane
        Vector2D delta;     // contains the x and y amounts that the object will move on each time unit

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D dest);

    public:
        Trainer();
        Trainer(char in_code);
        Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
        ~Trainer();
        void StartMoving(Point2D dest);
        void StartMovingToGym(PokemonGym* gym);
        void StartMovingToCenter(PokemonCenter* center);
        void StartBattling(unsigned int num_battles);
        void StartRecoveringHealth(unsigned int num_potions);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();
};

double GetRandomAmountOfPokeDollars();


#endif