// array_pointers.cpp

#include <iostream>

using namespace std;

int main()
{
    string text[] = {"banana", "melon", "apple", "mango", "pear"};

    cout
        << sizeof(text) / sizeof(string) << endl;

    // print array with array syntax
    for (int i = 0; i < sizeof(text) / sizeof(string); i++)
    {
        cout << text[i] << " " << flush;
    }
    cout << endl;

    // loop throuh an array using pointers 1: using array element reference syntax
    string *pt_text = text; // an array is a pointer to the first element of the array BOOM!

    for (int i = 0; i < sizeof(text) / sizeof(string); i++)
    {
        cout << pt_text[i] << " " << flush; // pointers are stored consecutively
    }
    cout << endl;

    // loop throuh an array using pointers 2: incrementing the pointer
    pt_text = text;

    for (int i = 0; i < sizeof(text) / sizeof(string); i++, pt_text++)
    {
        cout << *pt_text << " " << flush; // pointers are stored consecutively
    }
    cout << endl;

    // loop throuh an array using  pointers 3: stop by comparing two pointers
    string *pt_elem = text;    // pointer it to 1st elem in the array
    string *pt_end = &text[4]; // pointer to last elem of array. [] takes precedent over &

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

    return 0;
}