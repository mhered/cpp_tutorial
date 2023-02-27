// Cat.cpp

#include <iostream> // to use string, cout, cin, endl
#include <sstream>  // to use string streams
#include "Cat.h"

using namespace std;

// define constructor
Cat::Cat()
{
    cout << "Initializing Cat object..." << endl;
    // constructor is the proper place to initialize variables
    name = "Undefined";
    age = 0;
    happy = true;
}

Cat::Cat(string name, int age)
{
    this->name = name;
    this->age = age;
    this->happy = true;
}

// define destructor
Cat::~Cat()
{
    cout << "Cleaning up Cat object..." << endl;
}

// define public methods
void Cat::jump() const
{
    cout << "Jumping..." << endl;
}

// define methods to manipulate private state variables

// setters
void Cat::set_happy(bool happy)
{
    this->happy = happy; // private state variables are accesible from inside methods
}
void Cat::set_name(string name)
{
    this->name = name;
}
void Cat::set_age(int age)
{
    this->age = age;
}

// getters
string Cat::get_name()
{
    return name;
}

int Cat::get_age()
{
    return age;
}

bool Cat::get_happy()
{
    return happy;
}

string Cat::get_details()
{
    // uses IOstreams to concatenate strings and ints
    stringstream ss;
    ss << name << " is " << age << " y.o.";
    return ss.str();
}

// define public methods than depends on state variables
void Cat::speak() const
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
