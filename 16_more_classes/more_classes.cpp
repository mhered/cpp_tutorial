// more_classes.cpp

#include <iostream>
#include "Animal.h"

using namespace std;

Animal create_animal() // return a copy of an object
{
    Animal animal;
    animal.set_name("Paws");
    animal.set_age(10);
    return animal;
}

Animal *create_animal2() // return a pointer to a new object
{
    Animal *pt_animal = new Animal(); // using new ensures the object will not be limited to local scope
    pt_animal->set_name("Toby");
    pt_animal->set_age(12);
    return pt_animal;
}

int main()
{
    cout << "Create object" << endl;

    Animal animal1;
    animal1.set_name("Garfield");
    animal1.set_age(12);
    animal1.show_info();

    cout << "Create a copy with the copy constructor" << endl;
    Animal animal2 = animal1; // make a copy using a copy constructor (implicitly created if not defined)

    animal2.show_info();

    cout << "Create another copy with the copy constructor" << endl;
    Animal animal3(animal1); // another way of calling the copy constructor

    animal3.show_info();

    // another way to instantiate an object
    cout << "Create an object allocating memory with new and pointer" << endl;

    Animal *pt_animal = new Animal(); // allocate memory and return a pointer to a new Animal
    (*pt_animal).set_name("Snoopy");  // parenthesis needed because . has higher precedence than * ... Ugly!
    pt_animal->set_age(15);           // equivalent special syntax for object pointers and neater
    pt_animal->show_info();

    delete pt_animal; // need to explicitly delete to destroy object created with new, to avoid memory leaks!!

    // using a function that returns an object
    cout << "Create an object with a function that returns an object" << endl;
    Animal animal4 = create_animal(); // in theory this creates an object inside the function then a temporary copy,
                                      // then another copy to animal4, but compiler optimizes
                                      // potentially inefficient depending on the compiler
    animal4.show_info();

    // using a function that returns a pointer to an object created with new
    cout << "Create an object with a function that returns a new pointer" << endl;
    Animal *pt_animal5 = create_animal2(); // this returns a pointer to an object
    pt_animal5->show_info();
    delete pt_animal5; // remember to delete it to deallocate the memory and avoid  leak!!

    // allocating memory for an array of objects
    int N = 26;
    Animal *pt_animal6 = new Animal[N];

    for (int i = 0; i < N; i++)
    {
        char c = 'a';
        string name(1,c+i);
        pt_animal6[i].set_name(name);
        pt_animal6[i].set_age(i);

    }
    for (int i = 0; i < N; i++)
    {
        pt_animal6[i].show_info();
    }

    delete[] pt_animal6; // no need to specify the size

    // allocating a chunk of memory using chars (1 char = 1 byte)
    char *pt_mem = new char[1000];
    delete[] pt_mem;

    cout << "Terminating program..." << endl;

    return 0;
}