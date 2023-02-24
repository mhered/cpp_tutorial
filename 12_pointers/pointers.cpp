// pointers.cpp

#include <iostream>

using namespace std;

void manipulate_2(double *pt_value) // function to manipulate a value
{
    *pt_value = *pt_value * 2;
    cout << "Value inside function: " << *pt_value << endl;
}

void manipulate_1(double value) 
{
    value = value * 2;
    cout << "Value inside function: " << value << endl;
}

int main()
{
    // definea variable
    int var = 12;

    // define a pointer to the memory address where the variable is stored
    // of type int * (pointer to an int)
    int *pt_var = &var;

    cout << "var value: " << var << endl;
    cout << "var address: " << pt_var << endl;
    // getting the value by dereferencing the pointer
    // gets the value stored in the address
    cout << "var value via pointer: " << *pt_var << endl;
    cout << endl;

    double value = 2.5;
    cout << "Value before function: " << value << endl;
    // this function receives copy of the variable
    // changes do not persist
    manipulate_1(value); 
    cout << "Value after function: " << value << endl;
    cout << endl;

    cout << "Value before function: " << value << endl;
    //this function receives a pointer to the variable
    // changes persist
    manipulate_2(&value); //the parameter is the address of 'value'
    cout << "Value after function: " << value << endl;

    return 0;
}