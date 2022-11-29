// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "PokemonGym.h"

using namespace std;


PokemonGym :: PokemonGym() {
    display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;

    cout << "PokemonGym default constructed" << endl;
}

PokemonGym :: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) {
    id_num = in_id;
    max_number_of_battles = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    
    // ** initialize the rest of the member variables to default values **
    display_code = 'G';
    state = NOT_DEFEATED;
    num_battle_remaining = max_number_of_battles;

    cout << "PokemonGym constructed." << endl;
}

PokemonGym :: ~PokemonGym() {
    cout << "PokemonGym destructed" << endl;
    return;
}

double PokemonGym :: GetPokeDollarCost(unsigned int battle_qty) {
    // returns the cost of battling "battle_qty" times
    return PokeDollar_cost_per_battle * battle_qty;
}

unsigned int PokemonGym :: GetHealthCost(unsigned int battle_qty) {
    // returns the amount of health points required for "battle_qty" battles
    return health_cost_per_battle * battle_qty;
}

unsigned int PokemonGym :: GetNumBattlesRemaining() {
    // returns the number of battles remaining in PokemonGym
    return num_battle_remaining;
}

bool PokemonGym :: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) {
    // return true if trainer in PokemonGym with given budget and Pokemon health can request to take battle_qty battle
    if ((budget - GetPokeDollarCost(battle_qty) > 0) && (health - GetHealthCost(battle_qty))) {
        return true;
    }
    // return false otherwise
    return false;
}

unsigned int PokemonGym :: TrainPokemon(unsigned int battle_units) {
    unsigned int experience_gain;

    // instruction_1: subtracts battles from num_battles_remaining if the PokemonGym has enough units'
    // instruction_2: returns the amount of experience gained by winning the battles
    // instruction_1: if the amount of battles requested is greater than the amount available at the PokemonGym, then num_battles_remaining wll be used instead of battle_units when calculating experience gain
    // instruction_2: returns the amount of experience gained by winning the battles'
    // instruction_3: calculate experience points using (number of battles) * experience_per_battle
    if (num_battle_remaining >= battle_units) {
        num_battle_remaining -= battle_units;
        return battle_units * experience_per_battle;
    } else {
        experience_gain = num_battle_remaining * experience_per_battle;
        num_battle_remaining = 0;
        return experience_gain;
    }
}

unsigned int PokemonGym :: GetExperiencePerBattle() {
    // returns the experience gained from "each" battle
    return experience_per_battle;
}

bool PokemonGym :: Update() {
    if (num_battle_remaining == 0) {
        state = DEFEATED;
        display_code = 'g';
        cout << "(" << display_code << ")(" << id_num << ") has been beaten." << endl;
    } else {
        return false;
    }
}

bool PokemonGym :: passed() {
    if (num_battle_remaining == 0) {
        return true;
    }
}

void PokemonGym :: ShowStatus() {
    cout << "PokemonGymStatus: " << endl;
    this -> Building :: ShowStatus();
    cout << "Max number of battles: (" << max_number_of_battles << ")" << endl;
    cout << "Health cost per battle: (" << health_cost_per_battle << ")" << endl;
    cout << "PokeDollar per battle: (" << PokeDollar_cost_per_battle << ")" << endl;
    cout << "Experience per battle (" << experience_per_battle << ")" << endl;
    cout << "(" << num_battle_remaining << ") battle(s) are remaining for this PokemonGym" << endl;
}