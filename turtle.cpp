/**********************************************************************
* Program Name: turtle.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Implementation file for turtle class
* ********************************************************************/


#include "turtle.hpp"
#include <iostream>
#include "animal.hpp"
//intialize count
int Turtle::turtleCount = 0;
//constructor
Turtle::Turtle() : Animal()
{
    this->babies = 10;
    this->foodCost = foodCost * 0.5;
    this->payOff = cost * 0.05;
    turtleCount++;
}
//destructor
Turtle::~Turtle()
{
    turtleCount--;
}

int Turtle::getTurtleCount()
{
    return turtleCount;
}
