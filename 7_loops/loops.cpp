// loops.cpp

#include <iostream>
using namespace std;
int main()
{
    const int MAX = 16;

    // while loop
    int i = 0;
    while (i < MAX)
    {
        cout << "While loop " << i++ << endl; // i++ increments after executing the line, ++i before.
    };
    cout << endl;

    // do-while loop: always executes at least once (even if MAX == 0)
    int j = 0;
    do
    {
        cout << "Do-While loop " << j++ << endl;
    } while (j < MAX);
    cout << endl;

    // for loop
    for (int k = 0; k < MAX; k++)
    {
        cout << "For loop " << k << endl;
    }
    cout << endl;

    // use of break, continue
    for (int k = 0; k < MAX; k++)
    {
        if (k == 1)
        {
            cout << k << "st For loop" << endl;
            continue; //skips to next iteration
        }
        if (k == 2)
        {
            cout << k << "nd For loop" << endl;
            continue;
        }
        if (k == 3)
        {
            cout << k << "rd For loop" << endl;
            continue;
        }
        if (k == 11)
        {
            cout << "11 is too much! Exiting For loop... " << endl;
            break; // cancels iteration
        }
        cout << k << "th For loop" << endl;
    }
    cout << endl;

    return 0;
}