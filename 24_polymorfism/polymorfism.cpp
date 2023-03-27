// polymorfism.cpp

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()=0; // abstract class, makes compulsory that subclassess override this method
    virtual ~Animal(){};
};

class Cat : public Animal
{
public:
    virtual void speak()
    {
        cout << "purrr" << endl;
    }
    virtual ~Cat(){};
};

class HouseCat : public Cat
{
public:
    void speak()
    {
        cout << "miau!" << endl;
    }
    virtual ~HouseCat(){};
};

int main()
{
    Animal *pt_animal = new HouseCat;

    pt_animal->speak();

    delete pt_animal;
    return 0;
}