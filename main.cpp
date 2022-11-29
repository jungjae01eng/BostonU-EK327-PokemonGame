// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <stdlib.h>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"

using namespace std;


int main() {
    View v;
    Model m;
    char command;
    int a1, a2, a3;

    while (true){
        // initialize
        command = '0';
        a1 = 0;
        a2 = 0;
        a3 = 0;

        v.Clear();
        m.ShowStatus();
        m.Display(v);

        // user will enter
        cout << "Enter command: ";
        cin >> command;

        switch (command){
            case 'm': // move
                cin >> a1 >> a2 >> a3;
                DoMoveCommand(m, a1, Point2D(a2, a3));
                break;
            case 'c': // move to PokemonCenter
                cin >> a1 >> a2;
                DoMoveToCenterCommand(m, a1, a2);
                break;
            case 'g': // move to PokemonGym
                cin >> a1 >> a2;
                DoMoveToGymCommand(m, a1, a2);
                break;
            case 's': // stop
                cin >> a1;
                DoStopCommand(m, a1);
                break;
            case 'p': // buy potions_amount of potion at a PokemonCenter
                cin >> a1 >> a2;
                DoRecoverInCenterCommand(m, a1, a2);
                break;
            case 'b':
                cin >> a1 >> a2;
                DoBattleCommand(m, a1, a2);
                break;
            case 'a': // advance one-time step by updating each object once
                DoAdvanceCommand(m, v);
                break;
            case 'r': // run: advance one-time step and update each object, and repeat until either the update function returns true for at least one of the objects, or 5 time steps have been done
                DoRunCommand(m, v);
                break;
            case 'q': // quit
                return 0;
        }
    }
}