/**********************************************************************
* Program Name: animal.hpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: header file for animal class
* ********************************************************************/


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:

    int age;
    int cost;
    int babies;
    int foodCost;
    int payOff;

public:

    Animal();
    ~Animal();
    Animal& operator=(const Animal&);
    Animal (Animal&);
    int getAge() const;
    int getCost() const;
    int getBabies() const;
    int getFoodCost() const;
    int getPayOff() const;
    void setAge(int);
    void setCost(int);
    void setBabies(int);
    void setFoodCost(int);
    void setPayOff(int);
    int operator+(const Animal&) const;
    bool isAdult() const;
    void incAge();   
};
#endif
    
