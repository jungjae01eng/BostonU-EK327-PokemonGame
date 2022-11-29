// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "View.h"

using namespace std;


bool View :: GetSubscripts(int& out_x, int& out_y, Point2D location){
    // calculate the column and row subscripts of the grid array
    out_x = (location.x - origin.x) / scale;
    out_y = (location.y - origin.y) / scale;

    if((out_x < 0) && (out_y < 0) && (out_x > view_maxsize) || (out_y > view_maxsize)){
        cout << "An object is outside the display" << endl;
        return false;
    }
    return true;
}

View :: View(){
    // initialize size to 11
    size = 11;

    // initialize scale to 2
    scale = 2;

    // origin default to (0, 0)
    origin.x = 0;
    origin.y = 0;
    return;
}


void View :: Clear(){
    // sets all the cells of the grid to the background pattern
    for (int i = 0; i < view_maxsize; i++){
        for (int j = 0; j < view_maxsize; j++){
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
    return;
}

void View :: Plot(GameObject* ptr){
    // plots the pointed-to object in the proper cell of the grid
    // calls get_subscripts

    int x, y;

    if (GetSubscripts(x, y, ptr -> GetLocation())){
        if (grid[x][y][0] != '*'){
            grid[x][y][0] = ' ';
            grid[x][y][1] = ' ';
        } else{
            // getsubscripts are valid
            ptr->DrawSelf(grid[x][y]);
        }
    }
    return;
}

void View :: Draw(){
    // outputs the grid array to produce a display

    return;
}