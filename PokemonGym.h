// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Building.h"

using namespace std;


// prototyped
#ifndef POKEMONGYM_H
#define POKEMONGYM_H

class PokemonGym : public Building {
    // inherits from Building
    enum PokemonGymStates {
        NOT_DEFEATED = 0,
        DEFEATED = 1
    };

    private:
        unsigned int num_battle_remaining;      // amount of battles remaining in the PokemonGym
        unsigned int max_number_of_battles;     // number of battles for the PokemonGym
        unsigned int health_cost_per_battle;    // health of Pokemon lost for a single gym battle
        double PokeDollar_cost_per_battle;      // entry cost oof single battle
        unsigned int experience_per_battle;     // amount of experience gained from each class
    
    public:
        PokemonGym();
        PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
        ~PokemonGym();
        double GetPokeDollarCost(unsigned int battle_qty);
        unsigned int GetHealthCost(unsigned int battle_qty);
        unsigned int GetNumBattlesRemaining();
        bool IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health);
        unsigned int TrainPokemon(unsigned int battle_units);
        unsigned int GetExperiencePerBattle();
        bool Update();
        bool passed();
        void ShowStatus();
};


#endif