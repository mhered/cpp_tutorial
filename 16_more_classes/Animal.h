// Animal.h

#include <iostream>
using namespace std;

class Animal
{
private:
    string name;
    int age;

public:
    Animal() { cout << "Creating Animal..." << endl; };                                                      // constructor
    Animal(const Animal &other) : name(other.name), age(other.age) { cout << "Copying Animal..." << endl; }; // copy constructor
    ~Animal() { cout << "Destroying Animal..." << endl; };                                                  // receives a const object reference
    void set_name(string name) { this->name = name; };
    void set_age(int age) { this->age = age; };
    void show_info() const { cout << "My name is " << this->name << " and I am " << this->age << " years old." << endl; };
};
