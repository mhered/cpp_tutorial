// array_pointers.cpp

#include <iostream>

using namespace std;

int main()
{
    string fruits[] = {"banana", "melon", "apple", "mango", "pear"};

    cout
        << sizeof(fruits) / sizeof(string) << endl;

    // print array with array syntax
    for (int i = 0; i < sizeof(fruits) / sizeof(string); i++)
    {
        cout << fruits[i] << " " << flush;
    }
    cout << endl;

    // loop through an array using pointers 1: using array element reference syntax

    string *pt_fruits = fruits; // an array is a pointer to the first element of the array BOOM!

    for (int i = 0; i < sizeof(fruits) / sizeof(string); i++)
    {
        cout << pt_fruits[i] << " " << flush; // pointers are stored consecutively
    }
    cout << endl;

    // loop throuh an array using pointers 2: incrementing the pointer

    pt_fruits = fruits;

    for (int i = 0; i < sizeof(fruits) / sizeof(string); i++, pt_fruits++)
    {
        cout << *pt_fruits << " " << flush; // pointers are stored consecutively
    }
    cout << endl;

    // loop throuh an array using  pointers 3: stop by comparing two pointers
    string *pt_elem = fruits;    // pointer it to 1st elem in the array
    string *pt_end = &fruits[4]; // pointer to last elem of array. [] takes precedent over &

    while (true)
    {
        cout << *pt_elem << " " << flush; // pointers are stored consecutively
        if (pt_elem == pt_end)
        {
            break;
        }
        pt_elem++;
    }
    cout << endl;

    // pointer arithmetic

    const int N = 6; // compiler does not allow to change. Typically all capitals
    string numbers[N] = {"one", "two", "three", "four", "five", "six"};

    string *pointer = numbers;     // pointer to the first element of the array
    string *pt_last = &numbers[N]; // pointer BEYOND the last element of the array

    cout << *pointer << endl;

    // addition
    pointer += 3;
    cout << *pointer << endl;

    // subtraction
    pointer -= 2;
    cout << *pointer << endl;

    // reset pointer to start of array
    pointer = &numbers[0];

    // comparing pointers
    while (pointer != pt_last)
    {
        cout << *pointer << " " << flush;
        pointer++;
    }
    cout << endl;

    // reset pointer to start of array
    pointer = &numbers[0];

    long size_elements = (long)(pt_last - pointer); // cast it to a long and dont use it as pointer!!
    cout << size_elements << endl;

    // pointer to the middle of the array
    // reset pointer to start of array
    pointer = &numbers[0];

    pointer += N / 2; // integer division
    cout << *pointer << endl;

    return 0;
}