/**********************************************************************
* Program Name: animal.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Implementation file for animal class
* ********************************************************************/

#include "animal.hpp"
#include <iostream>

//constructor
Animal::Animal()
{
   this->age = 3;
   this->cost = 100;
   this->babies=1;
   this->foodCost=10;
   this->payOff = 100;
}
//destructor
Animal::~Animal(){}
//copy constructor
Animal::Animal(Animal &RHS)
{
   this->age = RHS.age;
   this->cost = RHS.cost;
   this->babies=RHS.babies;
   this->foodCost=RHS.foodCost;
   this->payOff = RHS.payOff;
}
//set one animal equal to another
Animal& Animal::operator=(const Animal &RHS)
{
   this->age = RHS.age;
   this->cost = RHS.cost;
   this->babies=RHS.babies;
   this->foodCost=RHS.foodCost;
   this->payOff = RHS.payOff;

   return *this;
}

int Animal::getAge() const
{
    return this->age;
}

int Animal::getCost() const
{
    return this->cost;
}

int Animal::getBabies() const
{
    return this->babies;
}

int Animal::getFoodCost() const
{
   return this->foodCost;
}

int Animal::getPayOff() const
{

   return this->payOff;
}

void Animal::setAge(int aAge) 
{
    this->age = aAge;
}

void Animal::setCost(int aCost) 
{
    this->cost = aCost;
}

void Animal::setBabies(int aBabies) 
{
    this->babies = aBabies;
}

void Animal::setFoodCost(int aFoodCost)
{
    this->foodCost = aFoodCost;
}

void Animal::setPayOff(int aPayOff)
{
    this->payOff = aPayOff;
}
//add cost of animals
int Animal::operator+(const Animal &RHS) const
{
    int sum = this->cost + RHS.cost;

    return sum;
}
//checks to see if animal is adult
bool Animal::isAdult() const
{
    if (this->age >=3)
    {
        return true;
    }

    else 
    {
        return false;
    }
}
//increases the age of an animal
void Animal::incAge()
{
    this->age = this->age + 1;
}
