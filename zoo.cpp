/**********************************************************************
* Program Name: zoo.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Implementation file for zoo class
* ********************************************************************/


#include "zoo.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "animal.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "validate.hpp"
using namespace std;

//constructor
Zoo::Zoo()
{
    this->tigerList = new Animal*[10];
    this->penguinList = new Animal*[10];
    this->turtleList = new Animal*[10];;
    this->bank = 100000;
    this->day = 0;
    this->tigerListSize = 10;
    this->penguinListSize = 10;
    this->turtleListSize = 10;
    
}

//destructor
Zoo::~Zoo(){};

Animal** Zoo::getTigerList()
{
    return this->tigerList;
}

Animal** Zoo::getPenguinList()
{
    return this->penguinList;
}

Animal** Zoo::getTurtleList()
{
    return this->turtleList;
}

int Zoo::getBank()
{
    return this->bank;
}

int Zoo::getDay()
{
    return this->day;
}

//resizes an array
void Zoo::reSizeArray(Animal** rhs, int size)
{ 
    Animal** tempArray = new Animal*[size*2];
    
    for (int i=0; i<size; i++)
    {
        tempArray[i] = rhs[i];
    }

    rhs=nullptr; 
    rhs = tempArray; 
    for(int i=0; i<size; i++)
    {
        rhs[i] = tempArray[i];
    }
    
}

//adds an animal to the list
void Zoo::growList(Animal** list, int amount)
{
    if (list == this->tigerList)
    {
        for(int i=0; i<amount; i++)
        {
            
            int count = Tiger::tigerCount;
             
 
            if(Tiger::tigerCount == 0)
            {
                this->tigerList[count] = new Tiger();
            }
            else if((count%10) == 0)
            {
                reSizeArray(tigerList, count);
                this->tigerList[count] = new Tiger();
            }
            else 
            {
                this->tigerList[count] = new Tiger();
            }
        }
    }
            
    else if (list == this->penguinList)
    {
        for(int i=0; i<amount; i++)
        {    
            int count = Penguin::penguinCount; 
 
            if(count == 0)
            {
                this->penguinList[count] = new Penguin();
            }
            else if((count%10) == 0)
            {
                reSizeArray(this->penguinList, count);
                this->penguinList[count] = new Penguin();
            }
            else 
            {
                this->penguinList[count] = new Penguin();
            }
        }
    }
        
    else if (list == this->turtleList)
    {
        for(int i=0; i<amount; i++)
        {
            
            int count = Turtle::turtleCount;
            if(count == 0)
            {
                this->turtleList[count] = new Turtle();
            }
            else if((count%10) == 0)
            {
                reSizeArray(this->turtleList, count);
                this->turtleList[count] = new Turtle();
            }
            else 
            {
                this->turtleList[count] = new Turtle();
            }
        }
    }
}

//subtracts the feeding cost of an animal
int Zoo::subFeedCost()
{
    int tigerSize = Tiger::tigerCount;
    int turtleSize = Turtle::turtleCount;
    int penguinSize = Penguin::penguinCount;
    int tigerDebt = 0;
    int penguinDebt = 0;
    int turtleDebt= 0;
    int total =0;
 
    if (Tiger::tigerCount !=0) 
    {
        tigerDebt = tigerSize * tigerList[0]->getFoodCost();
    }

    if (Penguin::penguinCount !=0) 
    {
        penguinDebt = penguinSize * penguinList[0]->getFoodCost();
    }

    if (Turtle::turtleCount !=0) 
    {
        turtleDebt = turtleSize * turtleList[0]->getFoodCost();
    }
    
    total = tigerDebt + penguinDebt + turtleDebt;
    this->bank = this->bank - total;
    return total;
}

//increments the current day
void Zoo::incDay()
{
    this->day = this->day + 1;
    
    for(int i=0; i<Tiger::tigerCount; i++)
    {
        this->tigerList[i]->incAge();
    }
    
    for(int i=0; i<Penguin::penguinCount; i++)
    {
        this->penguinList[i]->incAge();
    }
    
    for(int i=0; i<Turtle::turtleCount; i++)
    {
        this->turtleList[i]->incAge();
    }

}

//creates a random event
void Zoo::randomEvent()
{
    srand(time(NULL));
    int randNum = (1 + (rand() % 4));

    switch(randNum)
    {
        case 1:
        {
            int randomAnimal = 1+ (rand()%3); 
            if(randomAnimal == 1)
            {
                cout << "OH NO! One of your tigers has become sick and died\n"
                     << endl;

                delete this->tigerList[Tiger::tigerCount-1];
                Tiger::tigerCount = Tiger::tigerCount - 1;
            }
            else if(randomAnimal == 2)
            {
                cout << "OH NO! One of your penguins has become sick and died\n"
                     << endl;

                delete this->penguinList[Penguin::penguinCount-1];
                Penguin::penguinCount = Penguin::penguinCount - 1;
            }
            else if(randomAnimal == 3)
            {
                cout << "OH NO! One of your turtles has become sick and died\n"
                     << endl;

                delete this->turtleList[Turtle::turtleCount-1];
                Turtle::turtleCount = Turtle::turtleCount - 1;
            }
            
        }
        break;

        case 2:
        {
           int num = (250 +  (rand()%250));
            cout << "Attendance is booming! Profits are way up today! \n\n";
            cout << "You've received a $" << (Tiger::tigerCount * num)
                 << " bonus today!!\n\n";
            this->bank = bank + (Tiger::tigerCount * num);
            
        }
        break;

        case 3:
        {   
            
            int randomAnimal = 1+ (rand()%3); 
            if(randomAnimal == 1)
            {  
                for(int i=0; i<Tiger::tigerCount; i++)
                {
                    if(tigerList[i]->isAdult())
                    {
                        
                        cout << "One of your tigers has had a baby!\n"
                             << endl;

                        this->growList(tigerList, 1);
               
                        break;
                    }
                    else
                    {   
                        if(i == Tiger::tigerCount - 1)
                        {
                            cout << "Your tigers are growing fast!\n" << endl;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    
                }                                  
            }
            else if(randomAnimal == 2)
            {
                for(int i=0; i<Penguin::penguinCount; i++)
                {
                    if(penguinList[i]->isAdult())
                    {
                        
                        cout << "One of your penguins has had 5 babies!\n"
                             << endl;
                         
                        this->growList(penguinList, 5);
                        break;
                    }
                    else
                    {   if(i == Penguin::penguinCount - 1)
                        {
                            cout << "Your penguins are growing fast!\n" << endl;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    
                }                                  
 
            }
            else if(randomAnimal == 3)
            {
                for(int i=0; i<Turtle::turtleCount; i++)
                {
                    if(turtleList[i]->isAdult())
                    {
                       
                        cout << "One of your turtles has had 10 babies!\n"
                             << endl;

                        this->growList(turtleList, 10);

                        break;
                    }
                    else
                    {   
                        if(i == Turtle::turtleCount - 1)
                        {
                            cout << "Your turtles are growing fast!\n" << endl;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    
                }                                  
 
            }
 
        }
        break;

        case 4:
        {
            cout << "Just a typical day in the zoo, nothing special has happened today. \n";
        }
        break;
    }
}
//allows the user to buy a new animal
void Zoo::buyAnimal()
{
    int input;
    

    cout << "What type of animal would you like to buy? \n";
    cout << endl << "1. Tiger\n2. Penguin\n3. Turtle\n" << endl;
    cout << "\nSelect animal: ";
    validate(&input, 1, 3);
    

    switch(input)
    {
        case 1: 
        {
            growList(tigerList, 1);
            this->bank = this->bank - tigerList[0]->getCost();
        }
        break;

        case 2: 
        {
            growList(penguinList, 1);
            this->bank = this->bank - penguinList[0]->getCost();
        }
        break;

        case 3: 
        {
            growList(turtleList, 1);
            this->bank =  this->bank - turtleList[0]->getCost();
        }
        break;
    }
}

//deletes all memory
void Zoo::deleteAll()
{
    int tiger = Tiger::tigerCount;
    int penguin = Penguin::penguinCount;
    int turtle = Turtle::turtleCount;
    for (int i=0; i<tiger; i++)
    {
       delete tigerList[i];
    }

        
        delete [] tigerList;    
        
    for (int i=0; i<penguin; i++)
    {
        delete penguinList[i];
    } 
        
 
        delete [] penguinList;    
        

    for (int i=0; i<turtle; i++)
    {
       delete  turtleList[i];
    } 
    
       delete [] turtleList;  
    
}

//decreases cost of an animal from the bank
void Zoo::decCost(Animal** list)
{
    this->bank = this->bank - list[0]->getCost();
}   

//adds up total profits of animals
int Zoo::sumProfits()
{
    int tigerProfit = 0;
    int penguinProfit = 0;
    int turtleProfit = 0;

    if (Tiger::tigerCount != 0)
    {
        tigerProfit = Tiger::tigerCount * tigerList[0]->getPayOff();    
    }  
    if (Penguin::penguinCount != 0)
    {
        penguinProfit = Penguin::penguinCount * penguinList[0]->getPayOff();    
    }  

    if (Turtle::turtleCount != 0)
    {
        turtleProfit = Turtle::turtleCount * turtleList[0]->getPayOff();    
    }

    this->bank = this->bank + (tigerProfit + penguinProfit + turtleProfit);

    return tigerProfit + turtleProfit + penguinProfit;
}
