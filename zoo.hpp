/**********************************************************************
* Program Name: zoo.hpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Header file for animal class
* ********************************************************************/


#ifndef ZOO_HPP
#define ZOO_HPP
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "validate.hpp"

class Zoo
{

protected:

Animal** tigerList;
Animal** penguinList;
Animal** turtleList;
int bank;
int day;
int tigerListSize;
int penguinListSize;
int turtleListSize;

public:

Zoo();
~Zoo();
Animal** getTigerList();
Animal** getPenguinList();
Animal** getTurtleList();
int getBank();
int getDay();
void reSizeArray(Animal**, int);
void growList(Animal**, int size);
int subFeedCost();
void incDay(); 
void randomEvent();
void buyAnimal();
void deleteAll();
void decCost(Animal**);
int sumProfits();
friend void validate(int*, int, int);
};
#endif



