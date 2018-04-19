/**********************************************************************
* Program Name: penguin.hpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: header file for animal class
* ********************************************************************/


#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "animal.hpp"

class Penguin : public Animal
{
private:

public:

static int penguinCount;
Penguin();
~Penguin();
int getPenguinCount();

};
#endif


