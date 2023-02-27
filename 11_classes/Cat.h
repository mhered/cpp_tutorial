// Cat.h

// header file contains function prototypes
//  #ifndef - #endif precompilar instruciton to prevent including twice

#ifndef CAT_H_
#define CAT_H_

#include <iostream>

using namespace std;

class Cat // Cat class definition
{
private: // private instance variables describe state
    // encapsulated so they cannot be accessed from outside
    // need to be initialized or will contain garbage
    string name;
    int age;
    bool happy;

public: // public data and methods
        // public method prototypes
    // constructor (named same as class and no return type)
    Cat();
    // overloaded constructor with parameters, and inline definition
    Cat(string new_name) {name = new_name; age=0; happy = true;}
    // another overloaded constructor with parameters
    Cat(string name, int age);
    // an even better way using initialization list. Need empty implementation.
    Cat(string name, int age, bool happy): name(name), age(age), happy(happy) {};
    // destructor (named same as class and no return type)
    ~Cat();
    // setters
    void set_happy(bool is_happy);
    void set_name(string new_name);
    void set_age(int new_age);
    // getters
    string get_name();
    int get_age();
    bool get_happy();
    // actions
    void speak() const; // good practice to declare as const methods that won't change state
    void jump() const;

    string get_details();
};

#endif
