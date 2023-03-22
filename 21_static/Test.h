//  Test.h

#ifndef TEST_H_
#define TEST_H_

#include <iostream>

using namespace std;

class Test
{

public:
    // static variable makes one shared variable for all objects of the class
    static int public_static_variable;

    // classic use case: class constants
    //  initialization of const done at declaration
    static int const MAX = 99;

    // static methods can only access static variables
    static void show_count()
    {
        cout << count << " objects created so far" << endl;
    }
    int get_id()
    {
        return id;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    Test()
    {
        id = ++count;
        cout << "Creating object ID = " << id << endl;
    }

private:
    static int count;
    int id;
};

#endif