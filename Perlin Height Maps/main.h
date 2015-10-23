//
// Created by nwash on 9/11/2015.
//

#include <math.h>

#ifndef PERLIN_HEIGHT_MAPS_MAIN_H
#define PERLIN_HEIGHT_MAPS_MAIN_H

#endif //PERLIN_HEIGHT_MAPS_MAIN_H



void createCheckerBoardBmp(int width, int height);

class Vector
{
public:
    float x, y;
    float getLength()
    {
        return sqrtf(x*x + y*y);
    }
};

class Point
{
public:
    float x, y;
    Vector * getInnerVectors(int width, int height)
    {
        Vector vectors[4];

        //(0,0)
        vectors[0].x = x;
        vectors[0].y = y;
        //(0,1)
        vectors[1].x = x;
        vectors[1].y = static_cast<float>(height) - y;
        //(1,0)
        vectors[2].x = static_cast<float>(width) - x;
        vectors[2].y = y;
        //(1,1)
        vectors[3].x = static_cast<float>(width) - x;
        vectors[3].y = static_cast<float>(height) - y;

        Vector (*pVectors)[4] = &vectors;

        return *pVectors;
    };
};