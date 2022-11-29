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
#include "GameCommand.h"

using namespace std;


void DoMoveCommand(Model &model, int trainer_id, Point2D p1) {
    if ((model.GetTrainerPtr(trainer_id) != 0)) {
        model.GetTrainerPtr(trainer_id) -> StartMoving(p1);
        cout << "Moving " << (model.GetTrainerPtr(trainer_id)) -> GetName() << " to " << p1 << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoMoveToCenterCommand(Model &model, int trainer_id, int center_id) {
    if ((model.GetTrainerPtr(trainer_id) != 0) && (model.GetPokemonCenterPtr(center_id) != 0)) {
        cout << "Moving " << (model.GetTrainerPtr(trainer_id)) -> GetName() << " to Pokemon center " << center_id << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoMoveToGymCommand(Model &model, int trainer_id, int gym_id) {
    if ((model.GetTrainerPtr(trainer_id) != 0) && (model.GetPokemonGymPtr(gym_id) != 0)) {
        cout << "Moving " << (model.GetTrainerPtr(trainer_id)) -> GetName() << " to gym " << gym_id << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoStopCommand(Model &model, int trainer_id) {
    if ((model.GetTrainerPtr(trainer_id) != 0)) {
        model.GetTrainerPtr(trainer_id) -> Stop();
        cout << "Stopping " << (model.GetTrainerPtr(trainer_id)) -> GetName() << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoBattleCommand(Model &model, int trainer_id, unsigned int battles) {
    if ((model.GetTrainerPtr(trainer_id) != 0)) {
        model.GetTrainerPtr(trainer_id) -> StartBattling(battles);
        cout << (model.GetTrainerPtr(trainer_id)) -> GetName() << " is battling" << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoRecoverInCenterCommand(Model &model, int trainer_id, unsigned int potions_needed) {
    if ((model.GetTrainerPtr(trainer_id) != 0)) {
        model.GetTrainerPtr(trainer_id) -> StartRecoveringHealth(potions_needed);
        cout << "Recovering " << (model.GetTrainerPtr(trainer_id)) -> GetName() << endl;
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
    return;
}

void DoAdvanceCommand(Model &model, View &view) {
    // call Model::Update() to update all the objects
    // Model::Update();

    // call Model::Display() to display the current view of the game
    // Model::Display();

    cout << "Advancing one tick." << endl;
    return;
}

void DoRunCommand(Model &model, View &view) {
    // call Model::Update() to update all the objects
    // Model::Update();

    // call Model::Display() to display the current view of the game
    // Model::Display();

    cout << "Advancing to next event." << endl;
    return;
}