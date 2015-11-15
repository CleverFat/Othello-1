#include "elements.h"

short dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int initBoardValue[SAFE_LENGTH][SAFE_LENGTH] =
{
    {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8},
    {-8, 8,-2, 3, 3, 3, 3,-2, 8, -8},
    {-8, -2, 0, 2, 2, 2, 2, 0, -2, -8},
    {-8, 3, 2, 1, 1, 1, 1, 2, 3, -8},
    {-8, 3, 2, 1, 1, 1, 1, 2, 3, -8},
    {-8, 3, 2, 1, 1, 1, 1, 2, 3, -8},
    {-8, 3, 2, 1, 1, 1, 1, 2, 3, -8},
    {-8, -2, 0, 2, 2, 2, 2, 0, -2, -8},
    {-8, 8,-2, 3, 3, 3, 3,-2, 8, -8},
    {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8}
};

Cell NULLCELL[SAFE_LENGTH][SAFE_LENGTH]{};
short NULLCOUNT[4]{};