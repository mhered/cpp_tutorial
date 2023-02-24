// classes.cpp

#include <iostream> // first standard includes with <>
#include "Cat.h"    // then specific ones with "" (before namespace)

using namespace std;

int main()
{
    cout << "Running main()..." << endl;

    // declare an object of class Cat (i.e. instantiate a class)
    // constructor runs at creation and initializes variables

    {             // atypical use of {} to define a scope and when to deallocate memory early
        Cat cat1; // create an object with the basic constructor
        cout << cat1.get_details() << endl;
        // set private properties (or state variables) using public methods (setters)
        cat1.set_name("Garfield");
        cat1.set_age(7);
        cout << cat1.get_details() << endl;

        cat1.jump(); // call public method jump()

        cat1.speak(); // call public method speak()

        cat1.set_happy(false);
        cat1.speak(); // call public method speak()
    }

    Cat cat2("Paws", 1); // instantiate another cat passing parameters to the constructor
    cout << cat2.get_details() << endl;
    cat2.speak();

    Cat cat3("Tocinito", 18, false);
    cout << cat3.get_details() << endl;
    cat3.speak();

    cout << "Quitting..." << endl;
    return 0;
}