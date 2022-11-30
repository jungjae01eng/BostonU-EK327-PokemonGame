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
#include <math.h>
#include <string>
#include <time.h>   // generate random variables using time
#include "Trainer.h"

using namespace std;


Trainer :: Trainer() {
    // instruction_1: initializes the speed to 5
    speed = 5;

    // instruction_1: outputs a message: "Trainer default constructed!"
    cout << "Trainer default constructed!" << endl;
}

Trainer :: Trainer(char in_code) {
    // instruction_1: initializes the speed to 5
    speed = 5;

    // instruction_1: and outputs a message: "Trainer constructed!"
    cout << "Trainer constructed!" << endl;

    // instruction_2: initialize State = STOPPED
    state = STOPPED;

    // instruction_2: initialize Display_code = in_code
    display_code = in_code;
}

Trainer :: Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) {
    // instruction_1: initializes the speed to in_speed
    speed = in_speed;

    // instruction_1: sets name to in_name
    name = in_name;

    // instruction_2: outputs a message: "Trainer constructed!"
    cout << "Trainer constructed!" << endl;
}

Trainer :: ~Trainer() {
    // destructor
    cout << "Trainer destructed!" << endl;
}

void Trainer :: StartMoving(Point2D dest) {
    // tells the Trainer to start moving

    // instruction_2: calls the setup_destination() function
    destination = dest;
    this -> SetupDestination(destination);

    if (state == FAINTED) {
        // instruction_5: if the trainer is infected print "(display_code)(id): My pokemon have fainted. I may move, but you cannot see me."
        // if Trainer is fainted. Assume infected = fainted
        cout << display_code << id_num << ": My pokemon have fainted. I may move, but you cannot see me." << endl;
    } else if (GetDistanceBetween(destination, location) == 0) {
        // instruction_4: if the trainer is already at the destination, print "(display_code)(id): I'm already there. See?"
        // if the location is same as destination, it arrived
        cout << display_code << id_num << ": I am already there. See?" << endl;
    } else {
        if (state == IN_GYM) {
            current_gym -> RemoveOneTrainer();
        } else if (state == AT_CENTER) {
            current_center -> RemoveOneTrainer();
        }
        
       // instruction_3: sets the state to MOVING
        state = MOVING;

        // instruction_6: otherwise prints "(display_code)(id): On my way."
        cout << display_code << id_num << ": On my way." << endl;

        // ****** SetupDestination(dest);
    }
    return;
}

void Trainer :: StartMovingToGym(PokemonGym* gym) {
    // tells the Trainer to start moving to a PokemonGym
    current_gym = gym;

    // instruction_2: calls the SetupDestination() function with PokemonGym's location as the destination
    this -> SetupDestination(gym -> GetLocation()); // gym is a destination

    // instruction_3: sets the state to MOVING_TO_GYM
    state = MOVING_TO_GYM;

    if (state == FAINTED) {
        // instruction_4: if the Trainer is fainted, print "(display_code)(id): My Pokemon have fainted, so I can't move to gym..."
        cout << "(" << display_code << ")(" << id_num << "): My pokemon have fainted, so I can't move to gym..." << endl;
    } else if (GetDistanceBetween(destination, location) == 0) {
        // instruction_6: if the trainer is already there, print "(display_code)(id): I am already at the PokemonGym!"
        cout << "(" << display_code << ")(" << id_num << "): I am already at the PokemonGym!" << endl;
    } else {
        // instruction_5: prints the message "(display_code)(id): on my way to gym (gym id)."
        cout << "(" << display_code << ")(" << id_num << "): On my way to gym (" << gym->GetId() << ")" << endl;
    }
    return;
}

void Trainer :: StartMovingToCenter(PokemonCenter* center) {
    // tells the Trainer to start moving to a PokemonCenter
    current_center = center;

    // instruction_2: calls the SetupDestination() function with PokemonCenter's location as the destination
    this -> SetupDestination(center -> GetLocation());  // center is a destination

    // instruction_3: sets the state to MOVING_TO_CENTER
    state = MOVING_TO_CENTER;

    if (state == FAINTED) {
        // instruction_4: if the Trainer's pokemon have fainted, print "(display_code)(id): My pokemon have fainted, so I should have gone to the center..."
        cout << display_code << id_num << ": My pokemon have fainted, so I should have gone to the center..." << endl;
    } else if (GetDistanceBetween(destination, location) == 0) {
        // instruction_6: if Trainer is already there, print "(display_code)(id): I am already at the Center!"
        cout << display_code << id_num << ": I am already at the Center!" << endl;
    } else {
        // instruction_5: prints the message "(display_code)(id): On my way to Center (center id)."
        cout << display_code << id_num << ": On my way to Center " << center -> GetId() << "." << endl;
    }
    return;
}

void Trainer :: StartBattling(unsigned int num_battles) {
    // tells the Trainer to start battling (num_battles) in a PokemonGym
    // instruction_2: sets the state to BATTLING_IN_GYM
    state = BATTLING_IN_GYM;

    if (state == FAINTED) {
        // instruction_2: if Trainer's pokemon are too tired, prints the message "(display_code)(id): My Pokemon have fainted, so no more battles for me..."
        // assume "too tired" is FAINTED
        cout << display_code << id_num << ": My pokemon have fainted, so no more battles for me..." << endl;
    } else if (state != IN_GYM) {
        // instruction_2: if Trainer is not in a PokemonGym, prints the message "(display_code)(id): I can only battle in a PokemonGym!"
        cout << display_code << id_num << ": I can only battle in a PokemonGym!" << endl;
    } else if (PokeDollars < battles_to_buy) {
        // instruction_3: if Trainer does not have enough PokeDollars, prints "(display_code)(id): Not enough money for battles."
        cout << display_code << id_num << ": Not enough money for battles." << endl;
    } else if (current_gym -> passed() == true) {   // returns true if battles remaining is zero
        // instruction_4: if the current_gym is done, print "(display_code)(id): Cannot battle! This PokemonGym has no more trainers to battle!"
        cout << display_code << id_num << ": Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
    } else {
        // instruction_5: if the Trainer can start training, set its num_battles to the requested battles and update the remaining battles in the gym
        state = BATTLING_IN_GYM;

        if (num_battles > current_gym -> GetNumBattlesRemaining()) {
            // can battle but not as much as the requested - not enough battles remaining
            battles_to_buy = current_gym -> GetNumBattlesRemaining();
        } else {
            // have enough battles remaining
            battles_to_buy = num_battles;
        }
        // instruction_2: if above instruction_2 conditions are false, prints the message "(display_code): Started to battle at the PokemonGym (gym id) with (number of battles) battles."
        cout << display_code << ": Started to battle at the PokemonGym " << current_gym -> GetId() << " with " << num_battles << " battles." << endl;
    }
    return;
}

void Trainer :: StartRecoveringHealth(unsigned int num_potions) {
    // tells the Trainer to start recovering at a PokemonCenter

    if (PokeDollars < battles_to_buy) {
        // instruction_2: if the Trainer does not have enough PokeDollars, prints "(display_code)(id): Not enough money to recover health."
        cout << display_code << id_num << ": Not enough money to recover health." << endl;
    } else if (num_potions < 1) {
        // instruction_2: if the Pokemon Center does not have at least one potion remaining, print "(display_code)(id): Cannot recover! No potion remaining in this Pokemon Center."
        cout << display_code << id_num << ": Cannot recover! No potion remaining in this Pokemon Center." << endl;
    } else if (state != AT_CENTER) {
        // instruction_2: if the Trainer is not in a Pokemon Center, print "(display_code)(id): I can only recover health at a Pokemon Center!"
        cout << display_code << id_num << ": I can only recover health at a Pokemon Center!" << endl;
    } else {
        // start recovering!!
        // instruction_2: if above instruction_3 false, sets the state to RECOVERING_HEALTH
        state = RECOVERING_HEALTH;

        // instruction_2: if above instruction_3 false, prints the message "(display_code)(id): Started recovering (num_potions) potions at Pokemon Center (current_center_id)."
        cout << display_code << id_num << ": Started recovering " << num_potions << " potions at Pokemon Center " << current_center -> GetId() << "." << endl;

        // instruction_3: if the Trainer can start recovering health, set its potions_to_buy to the minimum of the requested potions'
        potions_to_buy = num_potions;

        // instruction_3: if the Trainer can start recovering health, update the remaining potions in the center
        unsigned int GetNumPotionRemaining(potions_to_buy);
        // ****************************************** is this correct? ^

        // instruction_4: Five health is recovered for each potion purchased
        health += (5 * num_potions);
    }

    return;
}

void Trainer :: Stop() {
    // tells the Trainer to stop doing whatever it was doing
    // instruction_2: sets the state to STOPPED
    state = STOPPED;

    // instruction_3: prints "(display_code)(id): Stopping..."
    cout << display_code << id_num << ": Stopping..." << endl;

    return;
}

bool Trainer :: HasFainted() {
    // instruction_1: returns true if health is 0
    if (health == 0) {
        // fainted
        return true;
    } else {
        // not fainted
        return false;
    }
}

bool Trainer :: ShouldBeVisible() {
    // instruction_1: returns true if the Trainer is NOT fainted
    if (HasFainted() == true) {
        // fainted: should not be visible
        return false;
    } else {
        // not fainted: should be visible
        return true;
    }
}

void Trainer :: ShowStatus() {
    // instruction_1: prints "(name) status: "
    cout << name << " status: " << endl;

    // instruction_2: call GameObject::ShowStatus()
    this -> GameObject::ShowStatus();

    // instruction_3: print state specific status information depends on Update() function
    switch(state) {
        case 0:     // STOPPED
            // instruction_1: ShowStatus() prints "stopped"
            cout << "   stopped" << endl;
            break;
        case 1:     // MOVING
            // instruction_1: ShowStatus() prints "moving at speed of (speed) to destination <x, y> at each step of (delta)."
            cout << "   moving at speed of " << speed << ") to destination <" << destination.x << ", " << destination.y << "> at each step of (" << delta << ")." << endl;
            break;
        case 2:     // FAINTED
            // quit the game
            // ****************************************** 
            break;
        case 3:     // AT_CENTER
            // instruction_1: ShowStatus() prints "inside Pokemon Center (current_Center id)."
            cout << "   inside Pokemon Center (" << current_center << ")." << endl;
            break;
        case 4:     // IN_GYM
            // instruction_1: ShowStatus() prints "inside PokemonGym (current_gym id)."
            cout << "   inside PokemonGym (" << current_gym << ")." << endl;
            break;
        case 5:     // MOVING_TO_CENTER
            // instruction_1: ShowStatus() prints "heading to PokemonCenter (current_Center id) at a speed of (speed) at each step of (delta)."
            cout << "   heading to PokemonCenter " << current_center << " at a speed of " << speed << " at each step of " << delta << "." << endl;
            break;
        case 6:     // MOVING_TO_GYM
            // instruction_1: ShowStatus() prints "heading to PokemonGym (current_gym id) at a speed of (speed) at each of (delta)."
            cout << "   heading to PokemonGym " << current_gym << " at a speed of " << speed << " at each of " << delta << "." << endl;
            break;
        case 7:     // BATTLING_IN_GYM
            // instruction_1: ShowStatus() prints "battling in PokemonGym (current_gym id)."
            cout << "   battling in PokemonGym " << current_gym << "." << endl;
            break;
        case 8:     // RECOVERING_HEALTH
            // instruction_1: ShowStatus() prints "recovering health in Pokemon Center (current_Center id)."
            cout << "   recovering health in Pokemon Center " << current_center << "." << endl;
            break;
    }
    return;
}

bool Trainer :: Update() {
    // Update() function contains a big switch statement

    // return true whenever the state is changed
    // ******************************************  

    // return false if the state stays the same
    // ******************************************  

    // all sates print "Health: (health)", "PokeDollars: (PokeDollars):, "Experience: (experience)"
    cout << "Health: " << health << endl;
    cout << "PokeDollars: " << PokeDollars << endl;
    cout << "Experience: " << experience << endl;

    // instruction_0: if Trainer runs out of health, print "(name) is out of health and can't move"
    if (health == 0) {
        cout << name << " is out of health and can't move" << endl;
    }

    // instruction_0: set state to FAINTED
    state = FAINTED;

    switch (state) {
        case STOPPED:
            // the Trainer does nothing and stays in this state
            // instruction_2: Update() return false
            return false;
        case MOVING:
            // instruction_2: Update() should call UpdateLocation() to take a step
            this -> UpdateLocation();

            if (GetDistanceBetween(destination, location) == 0) {
                // instruction_2: Update() should set the state to STOPPED if the object has arrived
                state = STOPPED;

                // instruction_2: Update() should return true if the object has arrived
                return true;
            } else {
                // instruction_2: Update() should stay in the MOVING state if it has not arrived yet
                state = MOVING;
                return false;
            }
        case FAINTED:
            // ****************************************** 
            break;
        case AT_CENTER:
            // instruction_2: Update() should return false
            return false;
        case IN_GYM:
            // instruction_2: Update() should return false
            return false;
        case MOVING_TO_CENTER:
            // instruction_2: Update() should call UpdateLocation()
            this -> UpdateLocation();

            if (GetDistanceBetween(destination, location) == 0) {
                // instruction_2: Update() should set the state to AT_CENTER if it has arrived
                state = AT_CENTER;

                // instruction_2: Update() should return true if it has arrived
                return true;
            } else if (GetDistanceBetween(destination, location) != 0) {
                // instruction_2: Update() should stay in the current state if it has not arrived yet
                state = MOVING_TO_CENTER;
                return false;
            }
            break;
        case MOVING_TO_GYM:
            // instruction_2: Update() should call UpdateLocation()
            this -> UpdateLocation();

            if (GetDistanceBetween(destination, location) == 0) {
                // arrived
                // instruction_2: Update() should set the state to IN_GYM if it has arrived
                state = IN_GYM;

                // instruction_2: Update() should return true if it has arrived
                return true;
            } else if (GetDistanceBetween(destination, location) != 0) {
                // instruction_2: Update() should be in the MOVING state if it has not arrived yet
                state = MOVING;
                return false;
            }
            break;
        case BATTLING_IN_GYM:
            unsigned int experience_gained;
            // instruction_2: Update() should reduce Trainer health based on total health cost for the current gym request
            health -= current_gym -> GetHealthCost(battles_to_buy);     // <in PokemonGym>

            // instruction_2: Update() should reduce the amount of PokeDollars based on the dollar cost for the current gym request
            PokeDollars -= current_gym -> GetPokeDollarCost(battles_to_buy);    // <in PokemonGym>

            // instruction_2: Update() should increase Trainer experience based on experience gain for the current gym request (should be calculated using TrainPokemon() function)
            experience_gained = current_gym -> TrainPokemon(battles_to_buy);   // <in PokemonGym>
            experience += experience_gained;

            // instruction_2: Update() should print "** (name) completed (battles_to_buy) battle(s)! **"
            cout << "** " << name << " completed " << battles_to_buy << " battle(s)! **" << endl;

            // instruction_2: Update() should print "** (name) gained (experience gained) experience! **"
            cout << "** " << name << " gained " << experience_gained << " experience! **" << endl;

            // instruction_2: Update() should set state to IN_GYM
            state = IN_GYM;

            // instruction_2: Update() should return true
            return true;
        case RECOVERING_HEALTH:
            // instruction_2: Update() should increase Health (Health should be calculated by StartRecoveringHealth() function)
            unsigned int prior_health = health;

            void StartRecoveringHealth(unsigned int num_potions);

            // instruction_2: Update() should reduce PokeDollars by the total cost of potions for the current PokemonCenter
            PokeDollars -= current_center -> GetPokeDollarCost(potions_to_buy); // <in PokemonCenter>

            // instruction_2: Update() should prints "** (name) recovered (health recovered) health! **"
            unsigned int health_gain = health - prior_health;
            cout << "** " << name << " recovered " << health_gain << " health! **" << endl;

            // instruction_2: Update() should prints "** (name) bought (potions_received) potion(s)! **"
            cout << "** " << name << " bought " << potions_to_buy << " potion(s)! **" << endl;

            // instruction_2: Update() should set state to AT_CENTER
            state = AT_CENTER;

            // instruction_2: Update() should return true
            return true;
    }
    return 0;
}

bool Trainer :: UpdateLocation() {
    // instruction_1: updates the object's location while it is moving

    if (fabs(destination.x - location.x) <= delta.x && fabs(destination.y - location.y) <= delta.y) {
        // an object is within the step of the destination
        location = destination;
    } else {
        this -> location.x += delta.x;
        this -> location.y += delta.y;
    }

    if (GetDistanceBetween(destination, location) == 0) {
        // instruction_2: if Trainer has arrived at its destination, prints "(display_code)(id): I'm there!"
        cout << display_code << id_num << ": I'm there!" << endl;

        // if arrived, return true
        return true;
    } else {
        // instruction_3: if instruction_2 is false, prints "(display_code)(id): step..."
        cout << display_code << id_num << ": step..." << endl;

        // instruction_0: decrease the health by 1 for each "speed-sized" step for any time the Trainer moves
        // instruction_0: increase the dollar count by a random amount for any time te Trainer moves

        return false;
    }
}

void Trainer :: SetupDestination(Point2D dest) {
    // sets up the object to start moving to destination
    destination = dest;

    delta.x = (destination.x - location.x) * (speed/GetDistanceBetween(destination, location));
    delta.y = (destination.y - location.y) * (speed/GetDistanceBetween(destination, location));

    return;
}

double GetRandomAmountOfPokeDollars() {
    // instruction_1: returns a random number between 0.0 and 2.0 inclusive
    // double min = 0.0;
    double max = 2.0;
    // double range = max - min + 1.0;

    srand(time(NULL));
    return rand() % 3 + max;    // "3" is a range. Since max is 2.0, min is 0.0, we calculate 2.0 - 0.0 + 1.0
}

string Trainer :: GetName() {
    return name;
}

//char Trainer :: GetState() {  // was going to create GetState; however, since Trainer is inherits from GameObject, we should have access to their GetState()
//    return state; // Getting an error
//}