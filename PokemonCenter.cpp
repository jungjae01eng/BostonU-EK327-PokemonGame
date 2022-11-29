// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

/*
 * "instruction" is the steps given on the assignments.
 * clarified it to organize and show difference between steps from the assignments and comment from myself
 */

// required header-file
#include <iostream>
#include <cmath>
#include "PokemonCenter.h"

using namespace std;


PokemonCenter :: PokemonCenter() {
    // instruction_1: display_code should be 'C' (Center)
    display_code = 'C';

    // instruction_2: potion_capacity should be 100
    potion_capacity = 100;

    // instruction_3: num_potions_remaining should be set to potion_capacity
    // initial number of potions in the PokemonCenter is the maximum
    num_potions_remaining = potion_capacity;

    // instruction_4: pokedollar_cost_per_potion should be set to 5
    pokedollar_cost_per_potion = 5;

    // instruction_5: state should be POTIONS_AVAILABLE
    // PokemonCenter contains set amount of potions
    state = POTIONS_AVAILABLE;

    // instruction_6: Print out the message "PokemonCenter default constructed!"
    cout << "PokemonCenter default constructed!" << endl;
}

PokemonCenter :: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) {
    // instruction_1: initialize the id number to in_id
    id_num = in_id;

    // instruction_1: initialize the location to in_loc
    location = in_loc;

    // instruction_1: initialize pokedollar_cost_per_potion to potion_cost
    pokedollar_cost_per_potion = potion_cost;

    // instruction_1: initialize potion_capacity to potion_cap
    potion_capacity = potion_cap;

    // instruction_3: state should be POTIONS_AVAILABLE
    state = POTIONS_AVAILABLE;

    // instruction_2: print out the message "PokemonCenter constructed!"
    cout << "PokemonCenter constructed!" << endl;

    // ** rest of the variables are assigned default values **
//    display_code = 'C';
//    num_potions_remaining = potion_capacity;
}

PokemonCenter :: ~PokemonCenter() {
    // destructor
    cout << "PokemonCenter destructed!" << endl;
}

bool PokemonCenter :: HasPotions() {
    // instruction_1: returns true if PokemonCenter contains at least one potion
    if (num_potions_remaining >= 1) {
        return true;
    } else {
        // instruction_2: returns false otherwise
        return false;
    }
 }

unsigned int PokemonCenter :: GetNumPotionRemaining() {
    // instruction_1: returns the number of potions remaining in the PokemonCenter
    return num_potions_remaining;
}

bool PokemonCenter :: CanAffordPotion(unsigned int potion, double budget) {
    // instruction_1: returns true if the trainer can afford to purchase potion with given budget
    if (pokedollar_cost_per_potion * potion <= budget) {
        // can afford potion
        return true;
    } else {
        return false;
    }
}

double PokemonCenter :: GetPokeDollarCost(unsigned int potion) {
    // instruction_1: returns pokedollar cost for specified number of potions
    return pokedollar_cost_per_potion * potion;
}

unsigned int PokemonCenter :: DistributePotion(unsigned int potion_needed) {
    // instruction_1: if num_potions_remaining >= potion_needed, it subtracts potion_needed from PokemonCenter amount and returns potion_needed
    if (num_potions_remaining >= potion_needed) {
        num_potions_remaining -= potion_needed
        return potion_needed;
    } else if (num_potions_remaining < potion_needed) {
        // instruction_1: if amount of potions in the PokemonCenter < potion_needed, it returns the PokemonCenter current amount, and the PokemonCenter potion amount is set to 0
        num_potions_remaining = 0;
         return num_potions_remaining;
    }
}

bool PokemonCenter :: Update() {
    // instruction_1: if PokemonCenter has no potions remaining, set state to NO_POTIONS_AVAILABLE
    // instruction_1: if PokemonCenter has no potions remaining, display_code to 'c'
    // instruction_1: if PokemonCenter has no potions remaining, print out "PokemonCenter (id number) has run out of potions."
    // instruction_1: if PokemonCenter has no potions remaining, returns true if potion is depleted
    if (num_potions_remaining == 0) {
        // unsure of instruction_2
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << GetId() << " has run out of potions." << endl;
        return true;
    } else if (num_potions_remaining > 0) {
        // instruction_1: returns false if it is not depleted
        return false;
    }
}

void PokemonCenter :: ShowStatus() {
    // instruction_1: outputs the message "PokemonCenter Status: "
    cout << "PokemonCenter Status: " << endl;

    // instruction_1: calls Building::ShowStatus()
    this -> Building :: ShowStatus();

    // instruction_1: outputs the message "PokeDollars per potion: (cost_per_potion)"
    // instruction_1: outputs the message "has (potion_remaining) potion(s) remaining."
    cout << "   PokeDollars per potion: " << pokedollar_cost_per_potion << endl;
    cout << "   has " << num_potions_remaining << " potion(s) remaining." << endl;

    return;
}