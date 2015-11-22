#include "elements.h"

short dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};


#if SIDE_LENGTH==8
short coordChara[SAFE_LENGTH][SAFE_LENGTH] =
{
    {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8},
    {-8,20,-3,11, 8, 8,11,-3,20,-8},
    {-8,-3,-7,-4, 1, 1,-4,-7,-3,-8},
    {-8,11,-4, 2, 2, 2, 2,-4,11,-8},
    {-8, 8, 1, 2,-3,-3, 2, 1, 8,-8},
    {-8, 8, 1, 2,-3,-3, 2, 1, 8,-8},
    {-8,11,-4, 2, 2, 2, 2,-4,11,-8},
    {-8,-3,-7,-4, 1, 1,-4,-7,-3,-8},
    {-8,20,-3,11, 8, 8,11,-3,20,-8},
    {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8}
};

#else
short coordChara[SAFE_LENGTH][SAFE_LENGTH]{};
#endif

double ALPHA = -2500;
double LOWERA = -10;
double LOWERB = 100;
double BETA = 2500;

Coord passCoord = {-1, -1};

Cell NULLCELL{};
