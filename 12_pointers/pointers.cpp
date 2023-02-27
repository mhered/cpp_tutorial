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
    // define a variable
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
    // this function receives a pointer to the variable
    //  changes persist
    manipulate_2(&value); // the parameter is the address of 'value'
    cout << "Value after function: " << value << endl;

    // const and pointers
    double number_1 = 1.2;
    double number_2 = 2.3;

    double *pt_1 = &number_1;             // pointer to a double
    const double *pt_2 = &number_1;       // pointer to a double that is constant
    double *const pt_3 = &number_1;       // constant pointer to a double
    const double *const pt_4 = &number_1; // constant pointer to a double that is constant

    cout << "double *pt_1 = &number_1;" << endl;
    cout << "-------------------------" << endl;
    cout << *pt_1 << endl;
    *pt_1 = 1.3; // can modify the value stored in this memory location
    cout << *pt_1 << endl;
    pt_1 = &number_2; // can point to a different memory location
    cout << *pt_1 << endl;

    cout << "const double *pt_2 = &number_1;" << endl;
    cout << "-------------------------------" << endl;
    cout << *pt_2 << endl;
    // *pt_2 = 1.2; // Error: cannot modify the value through this pointer
    cout << *pt_2 << endl;
    pt_2 = &number_2; // can point the pointer elsewhere
    cout << *pt_2 << endl;

    cout << "double *const pt_3 = &number_1;" << endl;
    cout << "-------------------------------" << endl;
    cout << *pt_3 << endl;
    *pt_3 = 1.2; // can modify the value through this pointer
    cout << *pt_3 << endl;
    // pt_3 = &number_2; // Error: cannot point the pointer elsewhere
    cout << *pt_3 << endl;

    cout << " const double *const pt_4 = &number_1;" << endl;
    cout << "--------------------------------------" << endl;
    cout << *pt_4 << endl;
    // *pt_4 = 1.2; // Error: cannot modify the value through this pointer
    cout << *pt_4 << endl;
    // pt_4 = &number_2; // Error: cannot point the pointer elsewhere
    cout << *pt_4 << endl;

    // References: different use of &
    int val1 = 8;
    int &val2 = val1; // this creates an alias instead of a copy of val1

    val2 = 10;

    cout << "Value 1: " << val1 << endl;
    cout << "Value 2: " << val2 << endl;

    return 0;
}