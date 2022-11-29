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
#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H

class PokemonCenter : public Building {
    // inherits from Building
    enum PokemonCenterStates {
        POTIONS_AVAILABLE = 0,
        NO_POTIONS_AVAILABLE = 1
    };

    private:
        unsigned int potion_capacity;   // the maximum number of potions the PokemonCenter can hold
        unsigned int num_potions_remaining; // the amount of potions currently in PokemonCenter
        double pokedollar_cost_per_potion;  // per potion cost in PokemonCenter

    public:
        PokemonCenter();
        PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);
        ~PokemonCenter();
        bool HasPotions();
        unsigned int GetNumPotionRemaining();
        bool CanAffordPotion(unsigned int potion, double budget);
        double GetPokeDollarCost(unsigned int potion);
        unsigned int DistributePotion(unsigned int potion_needed);
        bool Update();
        void ShowStatus();
};


#endif