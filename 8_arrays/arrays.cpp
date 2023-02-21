// arrays.cpp

#include <iostream>
using namespace std;
int main()
{
    // int array

    // declare
    int int_array[3];
    int other_int_array[3] = {}; // Alternative: declare and initialize to 0
    
    // initialize
    int_array[0] = 23;
    // int_array[1] = 2;
    int_array[2] = 67;

    cout << endl
         << "Int array" << endl;
    cout << "---------" << endl;

    cout << "item 0: " << int_array[0] << endl;
    cout << "item 1: " << int_array[1] << " (not initialized)" << endl; // if not initialized it contains garbage
    cout << "item 2: " << int_array[2] << endl;
    cout << "item 3: " << int_array[3] << " (bad idea)" << endl; // (!) nothing stops you from accessing element outside array


    // double array

    // declare and initialize
    double double_array[4] = {1.2, 4.7, 8.1, 7.5};

    cout << endl
         << "Double array" << endl;
    cout << "------------" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "item " << i << ": " << double_array[i] << endl;
    }

    // string array

    // declare and initialize. No need to specify dimension if initialized
    string string_array[] = {"hello", "this", "is", "an", "example"};

    cout << endl
         << "String array" << endl;
    cout << "------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "item " << i << ": " << string_array[i] << endl;
    }

    return 0;
}