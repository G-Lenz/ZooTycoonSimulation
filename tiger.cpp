/**********************************************************************
* Program Name: tiger.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Implementation file for tiger class
* ********************************************************************/


#include "tiger.hpp"
#include <iostream>
#include "animal.hpp"

//initialize total count
int Tiger::tigerCount = 0;
//constructor
Tiger::Tiger() : Animal()
{
    this->cost = cost * 100;
    this->foodCost = foodCost * 5;
    this->payOff = cost * 0.2;
    tigerCount++;
}
//destructor
Tiger::~Tiger()
{
    tigerCount--;
}

int Tiger::getTigerCount()
{
    return tigerCount;
}
