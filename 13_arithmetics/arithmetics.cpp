// arithmetics.cpp

#include <iostream>

using namespace std;

int main()
{
    // + - * / generally work as expected

    // careful with integer division
    int a = 13;
    int b = 5;
    double value1 = a / b; // result is 2 (integer division discards remainder)
    cout << value1 << endl;

    // % modulo operator yields the remainder of the integer division
    // 13/5 = 2 , remainder is 3
    cout << a << " / " << b << " = " << a / b << " , remainder is " << a % b << endl;

    // casting

    // cast at least one into double to get floating point division
    double value2 = (double)7 / 2; // result is 3.5
    cout << value2 << endl;

    int value3 = 7.3; // implicitly casts to int discarding decimal part
    cout << value3 << endl;
    // if compiler complains cast explicitly with:
    int value4 = (int)7.3;
    cout << value4 << endl;

    // += -= /= *= %= are increment operators
    value4 += 5; // is equivalent to value4 = value4 + 5
    cout << value4 << endl;

    // precedence rules are complicated
    // brackets provide better readibility
    double equation = ((5 / 4) % 2) + (2.3 * 6); // same but clearer than 5/4%2+2.3*6
    cout << equation << endl;

    // Exercise 1: converting seconds to hh::mm::ss

    int total_seconds = (5 * 60 * 60) + (12 * 60) + 23;
    cout << total_seconds << " secs = " << flush;
    int hrs = total_seconds / (60 * 60);
    total_seconds -= hrs * (60 * 60);
    int mins = total_seconds / 60;
    total_seconds -= mins * 60;
    int secs = total_seconds;

    cout << hrs << "hrs " << mins << " mins " << secs << " secs" << endl;

    // Exercise 2: print multiples of n smaller than N

    int N = 100;
    int n = 13;
    cout << "Multiples of " << n << " smaller than " << N << ":" << endl;
    for (int i = 0; i < N; i++)
    {
        if (i % n == 0)
        {
            cout << i << "  " << flush;
        }
    }
    cout << endl;
    return 0;
}