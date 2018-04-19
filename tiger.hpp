/**********************************************************************
* Program Name: tiger.hpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Header file for animal class
* ********************************************************************/



#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"

class Tiger : public Animal
{
protected:

public:
static int tigerCount;

Tiger();
~Tiger();
int getTigerCount();

};
#endif


