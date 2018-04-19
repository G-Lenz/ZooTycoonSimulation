/**********************************************************************
* Program Name: main.cpp
* Author Name: George Lenz
* Date: 2/4/2018
* Description: Runs the zoo tycoon game.
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

int main()
{
    int menuChoice = 0;
    int answer;
    int howMany;

    system("clear");

    cout << " ------------------------------\n"
         << "|                              |\n"
         << "|     **** ZOO TYCOON ****     |\n"
            "|                              |\n"
            " ------------------------------\n" << endl;

    cout << "      ** 1. Play Game **\n"
         << "      ** 2. Quit      **\n" << endl;

    cout << "Select an option: ";
    validate(&menuChoice, 1, 2);
    system("clear");
   
    if (menuChoice == 1)
    { 
        Zoo zoo1;

        cout << "Congratulations you own a zoo!!\n\n"
             << "The bank has given you 100,000 dollars to get started.\n";
         
        cout << "\nYou can buy from up to 3 animials! (Tigers, Penguins and Turtles)\n";
        cout << "\nTo start you may purchase up to 2 of each"
             << "\n**However, you must have AT LEAST 1 of each; "
             << "Afterall, no one wants a boring zoo!\n\n";
 
        cout << "How many tigers would you like to buy(cost: $10,000): ";
        validate(&howMany, 0, 2);
        zoo1.growList(zoo1.getTigerList(), howMany);
        for(int i=0; i<Tiger::tigerCount; i++)
        {
            zoo1.getTigerList()[i]->setAge(0);
            zoo1.decCost(zoo1.getTigerList());
        }
       
        cout << "\n\nHow many penguins would you like to buy(cost: $1,000): ";
        validate(&howMany, 0, 2);
        zoo1.growList(zoo1.getPenguinList(), howMany);
        for(int i=0; i<Penguin::penguinCount; i++)
        {
            zoo1.getPenguinList()[i]->setAge(0);
            zoo1.decCost(zoo1.getPenguinList());
        }
 
        cout << "\n\nHow many turtles would you like to buy(cost: $100): ";
        validate(&howMany, 0, 2);
        zoo1.growList(zoo1.getTurtleList(), howMany);
        for(int i=0; i<Turtle::turtleCount; i++)
        {
            zoo1.getTurtleList()[i]->setAge(0);
            zoo1.decCost(zoo1.getTurtleList());
        }

        zoo1.incDay();
       
        system("clear");
   
        cout << "Your zoo is officially ready to open!!\n\n";
        cout << "Press enter to open for business..." << endl;
        cin.ignore();
        system("clear");

        do
        {
            cout << "************************" << endl;  
            cout << "*       Day " << zoo1.getDay() << "          *" << endl;
            cout << "************************" << endl << endl;
         
            cout << "RISE AND SHINE!\n"
                 << "It's time to feed the animals!\n\n";

            cout << "Here is the receipt for the total feed cost.\n\n";
            cout << "------------------------------" << endl;
            cout << "Tiger Feed: $" << zoo1.getTigerList()[0]->getFoodCost()
                 << " x " << Tiger::tigerCount <<endl;
            cout << "Penguin Feed: $" << zoo1.getPenguinList()[0]->getFoodCost()
                 << " x " << Penguin::penguinCount <<endl;
            cout << "Turtle Feed: $" << zoo1.getTurtleList()[0]->getFoodCost()
                 << " x " << Turtle::turtleCount <<endl;
            cout << "TOTAL COST: $" << zoo1.subFeedCost() << endl << endl;
            cout << "-----------------------------" << endl << endl;
            cout << "Funds left in bank: $" << zoo1.getBank() << endl;
            cout << "Press ENTER to continue...";
            cin.ignore();
            system("clear");           
            cout << "************************" << endl;  
            cout << "*       Day " << zoo1.getDay() << "          *" << endl;
            cout << "************************" << endl << endl;

            cout << "Today's Events \n";
            cout << "--------------\n" << endl;
            zoo1.randomEvent();

            cout << "\nPress Enter to see your end of day totals...";
            cin.ignore();
            system("clear");

            cout << "************************" << endl;  
            cout << "*  Day " << zoo1.getDay() << " Summary  *" << endl;
            cout << "************************" << endl << endl;
            cout << "Inventory\n";
            cout << "---------\n";
            cout << "Number of tigers: " << Tiger::tigerCount << endl;
            cout << "Number of penguins: " << Penguin::penguinCount << endl;
            cout << "Number of turtles: " << Turtle::turtleCount << endl << endl;
            cout << "Profits\n";
            cout << "-------\n";
            cout << "Tigers: $" << zoo1.getTigerList()[0]->getPayOff()
                 << " x " << Tiger::tigerCount << endl;
            cout << "Penguins: $" << zoo1.getPenguinList()[0]->getPayOff()
                 << " x " << Penguin::penguinCount << endl;
            cout << "Turtles: $" << zoo1.getTurtleList()[0]->getPayOff()
                 << " x " << Turtle::turtleCount << endl;
 
            cout << "Total profits: $" << zoo1.sumProfits() << endl;

            cout << "Bank" << endl;
            cout << "----" << endl;
            cout << "Total money in bank: $" << zoo1.getBank() <<endl <<endl;

            cout << "Press ENTER to continue ...";
            cin.ignore();
            system("clear");

            if (zoo1.getBank() <= 0)
            {
                 cout << "You've gone broke!!\n\n";
                 cout << "Press enter to quit...";
                 cin.ignore();
                 break;
            }

            cout << "Would you like to buy another animal?\n";
            cout << "1. Yes\n2. No\n3. Quit Program\n";
            cout << "Choose item: ";
            validate(&answer, 1, 3);
            cout << endl;
            if(answer == 1)
            {
                zoo1.buyAnimal();
               cout << "\nSuccessfuly Purchased!\n";
              
            }
            
            else if(answer == 3)
            {
                break;
            }
            cout << "\nPress ENTER to advance to the next day...";
            cin.ignore();
            system("clear");
            zoo1.incDay();
        

        }while(answer != 3); 
        system("clear");
        cout << "GAME OVER" << endl << endl; 
        zoo1.deleteAll(); 
    }
    
    return 0;            
}
