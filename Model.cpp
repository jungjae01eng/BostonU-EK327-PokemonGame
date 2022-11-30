// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

/*
 * "instruction" is the step given by assignments.
 * clarified it to organize and show difference between steps and notes from myself
 */

// required header-file
#include <iostream>
#include <cmath>
#include <time.h>   // to generate random variables
#include "Trainer.h"
#include "Model.h"

using namespace std;


Model :: Model() {
    // instruction_1: initializes the time to 0
    time = 0;

    // instruction_2: creates the objects using new, and stores the pointers to them in the arrays.
    // Trainer
    Trainer* T1 = new Trainer("Ash", 1, 'T', 1, Point2D(5, 1));
    object_ptrs[0] = T1;
    trainer_ptrs[0] = T1;

    Trainer* T2 = new Trainer("Misty", 2, 'T', 2, Point2D(10, 1));
    object_ptrs[1] = T2;
    trainer_ptrs[1] = T2;

    // PokemonCenter
    PokemonCenter* C1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    object_ptrs[2] = C1;
    center_ptrs[0] = C1;

    PokemonCenter* C2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
    object_ptrs[3] = C2;
    center_ptrs[1] = C2;

    // PokemonGym
    PokemonGym* G1 = new PokemonGym(10, 1, 2, 3, 1, Point2D(0, 0));
    object_ptrs[4] = G1;
    gym_ptrs[0] = G1;

    PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5));
    object_ptrs[5] = G2;
    gym_ptrs[1] = G2;

    // initialize
    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;

    return;
}

Model :: ~Model() {
    // destructor
    cout << "Model destructed" << endl;
    return;
}

Trainer* Model :: GetTrainerPtr(int id) {
    // search the appropriate array for an object matching the supplied id, and either return the pointer if found or 0 if not
    for (int i = 0; i < num_trainers; i++) {
        if (trainer_ptrs[i] -> GetId() == id) {
            return trainer_ptrs[i];
        }
    }
     return 0;
}

PokemonCenter* Model :: GetPokemonCenterPtr(int id) {
    // search the appropriate array for an object matching the supplied id, and either return the pointer if found or 0 if not
    for (int i = 0; i < num_centers; i++) {
        if (trainer_ptrs[i] -> GetId() == id) {
            return center_ptrs[i];
        }
    }
    return 0;
}

PokemonGym* Model :: GetPokemonGymPtr(int id) {
    // search the appropriate array for an object matching the supplied id, and either return the pointer if found or 0 if not
    for (int i = 0; i < num_gyms; i++) {
        if (gym_ptrs[i] -> GetId() == id) {
            return gym_ptrs[i];
        }
    }
    return 0;
}

bool Model :: Update() {
    // increments the time
    time ++;

    // iterates throughout the object_ptrs array

//    for () {
//         // calls Update() for each object - GameObject::Update() - made virtual
//        bool GameOb = object_ptrs -> Update();
//         // return true if any one of the GameObject::Update() calls returned true
//    }
    if ((gym_ptrs[0] -> GetNumBattlesRemaining() == 0) && gym_ptrs[1] -> GetNumBattlesRemaining() == 0) {
        // if the player finished all the PokemonGyms, print "GAME OVER: You win! All battles done!"
        // no more battles remaining
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);    // exit the game
    }
    else if ((trainer_ptrs[0] -> GetState() == 2) && (trainer_ptrs[1] -> GetState() == 2)) {    // if I put "FAINTED", it makes an error
        // if all Trainers are fainted and can't move, print "GAME OVER: You lose! All of your Trainers' pokemon have fainted!"
        cout << "GAME OVER: You lose! All of your Trainers' pokemon have fainted!" << endl;
        exit(0);    // exit the game
    }
    return false;
}

void Model :: Display(View &view) {
    // outputs the time
    // cout << time << endl;

    // generates the view display for all the GameObjects

    return;
}

void Model :: ShowStatus() {
    // outputs the time
    // cout << time << endl;

    // outputs the status of all the GameObjects by calling their ShowStatus() function

    return;
}