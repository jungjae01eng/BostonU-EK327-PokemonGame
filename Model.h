// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "GameObject.h"
#include "Trainer.h"
#include "Building.h"
#include "View.h"
//#include "Input_Handling.h"
#include <list>

using namespace std;


// prototyped
#ifndef MODEL_H
#define MODEL_H

class Model 
{
    private:
    int time;
    list <GameObject*> object_ptrs;
    list <GameObject*> active_ptrs;
    list <Trainer*> trainer_ptrs;
    list <PokemonCenter*> center_ptrs;
    list <PokemonGym*> gym_ptrs;

    public:
    Model();
    ~Model();
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    //Functions for Object creation
    void NewCommand(char, int, double, double);
};


#endif