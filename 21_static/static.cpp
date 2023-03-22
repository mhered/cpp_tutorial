// static

#include <iostream>
#include "Test.h"
using namespace std;

int main()
{
    cout << "Public class variable: " << Test::public_static_variable << endl;
    cout << "Public class constant: " << Test::MAX << endl;

    Test::show_count();

    // allocating memory for an array of objects
    int N = 5;
    Test *pt_test = new Test[N];

    Test::show_count();

    return 0;
}