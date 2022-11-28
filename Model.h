// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>


// prototyped
#ifndef MODEL.H
#define MODEL.H

class Model {
    private:
        int time;
        GameObject *object_ptrs[10];
        int num_objects;
        Trainer *trainer_pts[10];
        int num_trainers;
        PokemonCenter *center_ptrs[10];
        int num_centers;
        PokemonGym *gym_ptrs[10];
        int num_gyms;
    public:
        Model();
        ~Model();
        Trainer *GetTrainerPtr(int id);
        PokemonCenter *GetPokemonCenterPtr(int id);
        PokemonGym *GetPokemonGymPtr(int id);
        bool Update();
        void Display(view &view);
        void ShowStatus();
};


#endif