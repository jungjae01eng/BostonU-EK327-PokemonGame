// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Building.h"


// prototyped
#ifndef POKEMONCENTER.H
#define POKEMONCENTER.H

class PokemonCenter : public Building {
    // inherits from Building
    enum PokemonCenterStates {
        POTIONS_AVAILABLE = 0,
        NO_POTIONS_AVAILABLE = 1
    };

    private:
        unsigned int potion_capacity;
        unsigned int num_potions_remaining;
        double pokedollar_cost_per_potion;

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