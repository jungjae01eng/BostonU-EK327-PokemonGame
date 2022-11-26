// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required headerfile
#include <iostream>
#include <cmath>
#include "PokemonCenter.h"

using namespace std;


PokemonCenter :: PokemonCenter() {
    // display_code should be 'C'
    // potion_capacity should be 100
    // num_potions_remaining should be set to potion_capacity
    // pokedollar_cost_per_potion should be set to 5
    // state should be POTIONS_AVAILABLE
    // Print out the message "PokemonCenter default constructed"
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter :: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) {
    // initialize id number to in_id
    // initialize location to in_loc
    // initialize pokedollar_cost_per_potion to potion_cost
    // initialize potion_capacity to potion_cap
    // state should be POTIONS_AVAILABLE
    // print out the message "PokemonCenter constructed"
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    state = POTIONS_AVAILABLE;

    // ** rest of the variables are assigned default values **
    display_code = 'C';
    num_potions_remaining = potion_capacity;

    cout << "PokemonCenter constructed" << endl;
}

bool PokemonCenter :: HasPotions() {
    // returns true if PokemonCenter contains at least one potion
    // returns false otherwise
    if (potion_capacity >= 1) {
        return true;
    } else {
        return false;
    }
 }

unsigned int PokemonCenter :: GetNumPotionRemaining() {
    // returns the number of potions remaining in the PokemonCenter
    return potion_capacity;
}

bool PokemonCenter :: CanAffordPotion(unsigned int potion, double budget) {
    // returns true if the trainer can afford to purchase potion with given budget
    if (pokedollar_cost_per_potion * potion <= budget) {
        // can afford potion
        return true;
    } else {
        return false;
    }
}

double PokemonCenter :: GetPokeDollarCost(unsigned int potion) {
    // returns pokedollar cost for specified number of potions
    return pokedollar_cost_per_potion * potion;
}

unsigned int PokemonCenter :: DistributePotion(unsigned int potion_needed) {
    // if num_potions_remaining >= potion_needed, it subtracts potion_needed from PokemonCenter amount and returns potion_needed
    // if amount of potions in the PokemonCenter is less "than potion_needed", it returns the PokemonCenter current amount, and the PokemonCenter potion amount is set to 0
    if (num_potions_remaining >= potion_needed) {
        return (potion_needed - num_potions_remaining);
    } else if (potion_capacity < potion_needed) {
        potion_capacity = 0;
        // return budget;
    }
}

bool PokemonCenter :: Update() {
    // if PokemonCenter has no potions remaining:
    //  state to NO_POTIONS_AVAILABLE
    //  display_code to 'c'
    //  print out "PokemonCenter (id number) has ran out of potions."
    //  returns true if potion is depleted
    //  returns false if it is not depleted
    state = NO_POTIONS_AVAILABLE;
    display_code = 'c';
    cout << "PokemonCenter (" << GetId() << ") has ran out of potions." << endl;
    
    if (potion_capacity > 0) {
        return false;
    } else if (potion_capacity == 0) {
        return true;
    }
}

void PokemonCenter :: ShowStatus() {
    // outputs the message "PokemonCenter Status: "
    // outputs cals Building::ShowStatus()
    // outputs the message "PokeDollars per potion: (cost_per_potion)"
    // outputs the message "has (potion_remaining) potion(s) remaining."
    cout << "PokemonCenter Status: ";
    // cout << ShowStatus() << endl;
    cout << "PokeDollars per potion: (" << pokedollar_cost_per_potion << ")" << " has (" << num_potions_remaining << ") potion(s) remaining.";
}