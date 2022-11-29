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
#include "PokemonGym.h"

using namespace std;


PokemonGym :: PokemonGym() {
    // instruction_1: display code should be 'G' (Gym)
    display_code = 'G';

    // instruction_2: state should be NOT_DEFEATED
    // initial state
    state = NOT_DEFEATED;

    // instruction_3: max number of battles should be 10
    max_number_of_battles = 10;

    // instruction_4: number battle remaining should be set to maximum number of battles
    // initial number of battles (10)
    num_battle_remaining = max_number_of_battles;

    // instruction_5: health cost per battle should be 1
    health_cost_per_battle = 1;

    // instruction_6: PokeDollar cost per battle should be 1.0
    PokeDollar_cost_per_battle = 1.0;

    // instruction_7: experience per battle should be 2
    experience_per_battle = 2;

    // instruction_8: print out the message "PokemonGym default constructed!"
    cout << "PokemonGym default constructed!" << endl;
}

PokemonGym :: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) {
    // instruction_1: initializes the id number to in_id
    id_num = in_id;

    // instruction_2: initializes max_number_of_battles to max_battle
    max_number_of_battles = max_battle;

    // instruction_3: initialize health_cost_per_battle to health_loss
    health_cost_per_battle = health_loss;

    // instruction_4: initialize experience_per_battle to exp_per_battle
    experience_per_battle = exp_per_battle;

    // instruction_5: initialize PokeDollar_cost_per_battle to PokeDollar_cost
    PokeDollar_cost_per_battle = PokeDollar_cost;

    // instruction_5: initialize location to in_loc
    location = in_loc;

    // instruction_6: initializes the rest of the member variables to default values
    display_code = 'G';
    state = NOT_DEFEATED;
    num_battle_remaining = max_number_of_battles;

    // instruction_7: prints out the message: "PokemonGym constructed!"
    cout << "PokemonGym constructed!" << endl;
}

PokemonGym :: ~PokemonGym() {
    // destructor
    cout << "PokemonGym destructed!" << endl;
}

double PokemonGym :: GetPokeDollarCost(unsigned int battle_qty) {
    // instruction_1: returns the cost of battling "battle_qty" times
    return PokeDollar_cost_per_battle * battle_qty;
}

unsigned int PokemonGym :: GetHealthCost(unsigned int battle_qty) {
    // instruction_1: returns the amount of health points required for "battle_qty" battles
    return health_cost_per_battle * battle_qty;
}

unsigned int PokemonGym :: GetNumBattlesRemaining() {
    // instruction_1: returns the number of battles remaining in PokemonGym
    return num_battle_remaining;
}

bool PokemonGym :: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) {
    // instruction_1: return true if a Trainer in a PokemonGym with a given budget and Pokemon health can request to take battle_qty battle
    if ((budget - GetPokeDollarCost(battle_qty) > 0) && (health - GetHealthCost(battle_qty))) {
        return true;
    } else {
        // instruction_2: return false otherwise
        return false;
    }
}

unsigned int PokemonGym :: TrainPokemon(unsigned int battle_units) {
    // instruction_1: subtracts battles from num_battles_remaining if the PokemonGym has enough units'
    // instruction_1: if the amount of battles requested is greater than the amount available at the PokemonGym, then num_battles_remaining wll be used instead of battle_units when calculating experience gain
    // instruction_2: returns the amount of experience gained by winning the battles'
    if (num_battle_remaining >= battle_units) {
        // PokemonGym has enough units
        num_battle_remaining -= battle_units;
        return num_battle_remaining * experience_per_battle;    // return experience gained
    } else {
        // instruction_3: calculate experience points using (number of battles) * experience_per_battle
        return battle_units * experience_per_battle;    // return experience gained
    }
}

unsigned int PokemonGym :: GetExperiencePerBattle() {
    // instruction_1: returns the experience gained from "each" battle
    return experience_per_battle;
}

bool PokemonGym :: Update() {
    // unsure of instruction_3
    if (passed() == true) {
        // should not keep returning true if the PokemonGym is passed.
        return true;
    } else if (num_battle_remaining == 0) {
        // instruction_1: if the PokemonGym has zero battles remaining, set the state to DEFEATED
        state = DEFEATED;

        // instruction_1: if the PokemonGym has zero battles remaining, set the display code to 'g'
        display_code = 'g';

        // instruction_1: if the PokemonGym has zero battles remaining, print "(display_code)(id) has been beaten."
        cout << display_code << id_num << " has been beaten." << endl;

        return true;
    } else {
        // instruction_2: return false if battles still remain within the PokemonGym
        return false;
    }
}

bool PokemonGym :: passed() {
    // instruction_1: returns true if battles remaining is zero
    if (num_battle_remaining == 0) {
        return true;
    } else {
        return false;
    }
}

void PokemonGym :: ShowStatus() {
    // prints out the status of the object
    cout << "PokemonGymStatus: " << endl;
    this -> Building :: ShowStatus();
    cout << "   Max number of battles: (" << max_number_of_battles << ")" << endl;
    cout << "   Health cost per battle: (" << health_cost_per_battle << ")" << endl;
    cout << "   PokeDollar per battle: (" << PokeDollar_cost_per_battle << ")" << endl;
    cout << "   Experience per battle (" << experience_per_battle << ")" << endl;
    cout << "   " << num_battle_remaining << " battle(s) are remaining for this PokemonGym" << endl;

    return;
}