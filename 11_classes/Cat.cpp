// Cat.cpp

#include <iostream>
#include "Cat.h"

using namespace std;

// define a public methods
void Cat::jump()
    cout << "Jumping..." << endl;
}

// define methods to manipulate private state variables
void Cat::make_happy()
{
   happy=true; //private state variables are accesible from inside methods
}

void Cat::make_sad()
{
   happy=false;
}

// define public methods than depends on state variables
void Cat::speak() 
{
    if (happy)
    {
        cout << "Miau!!" << endl;
    }
    else
    {
        cout << "Fffff!!" << endl;
    }
}


