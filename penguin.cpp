/**********************************************************************
* Program Name: penguin.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Implementation file for penguin class
* ********************************************************************/


#include "penguin.hpp"
#include <iostream>
#include "animal.hpp"
//set count to 0
int Penguin::penguinCount = 0;
//constructor
Penguin::Penguin() : Animal()
{
    this->cost = cost * 10;
    this->babies = 5;
    this->payOff = cost * 0.1;
    penguinCount++;
}
//destructor
Penguin::~Penguin()
{
    penguinCount--;
}

int Penguin::getPenguinCount()
{
    return penguinCount;
}
