// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"


// prototyped
#ifndef PA_3_VIEW_H
#define PA_3_VIEW_Hs

class View {
    private:
        int size;
        double scale;
        Point2D origin;
        char grid[view_maxsize][view_maxsize][2];
        bool GetSubscripts(int &out_x, int &out_y, Point2D location);
    public:
        view();
        void clear();
        void Plot();
//    void DrawSelf(char *ptr);
//    const int view_maxsize = 20;

};



#endif //PA_3_VIEW_H
