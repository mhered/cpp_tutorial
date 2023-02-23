// classes.cpp

#include <iostream> // first standard includes with <>
#include "Cat.h"    // then specific ones with "" (before namespace)

using namespace std;

int main()
{
    Cat paws; // declare an object of class Cat
    Cat garfield;
    
    garfield.make_happy(); // set private state variable through public method
    garfield.speak(); // call public method speak()

    paws.make_sad();
    paws.speak();


    paws.jump(); // call public method jump()

    return 0;
}