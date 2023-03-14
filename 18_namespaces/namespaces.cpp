// namespaces.cpp

#include <iostream>
#include "Cat.h"
#include "CopyCat.h"

using namespace std;

using namespace cat; // use Cat class defined in Cat.h
// using namespace copycat; // use Cat class defined in CopyCat.h

int main()
{
    Cat cat1; // Cat object in default namespace
    cout << NAME << " says: " << endl;
    cat1.speak(); // global const in default namespace

    cat::Cat cat2;                          // select cat namespace explicitly
    cout << cat::NAME << " says: " << endl; // global const in cat namespace
    cat2.speak();

    copycat::Cat cat3;                          // select copycat namespace explicitly
    cout << copycat::NAME << " says: " << endl; // global const in copycat namespace
    cat3.speak();

    return 0;
}