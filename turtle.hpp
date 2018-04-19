/**********************************************************************
* Program Name: turtle.hpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Header file for turtle class
* ********************************************************************/


#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "animal.hpp"

class Turtle : public Animal
{
private:

public:

static int turtleCount;
Turtle();
~Turtle();
int getTurtleCount();

};
#endif


