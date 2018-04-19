/**********************************************************************************************
* Progam Name: validate.cpp
* Author: George Lenz
* Date: 1/28/2018
* Description: Function to validate integer inputs.
*********************************************************************************************/

#include "validate.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

void validate(int* input, int min, int max)
{
            do
            {
                while (!(std::cin >> *input))
                {
                    std::cout << "ERROR: Please enter a valid integer: \n";
                    std::cin.clear();
                    std::cin.ignore(500, '\n');
                }
                std::cin.ignore(500, '\n');
                if (*input < min)
                {
                    std::cout << "ERROR: Please enter a number greater than or equal to " << min << endl;
                }
                else if (*input > max)
                {
                    std::cout << "ERROR: Please enter a number less than or equal to " << max << endl;
                }
            }while(*input < min || *input > max);
}

