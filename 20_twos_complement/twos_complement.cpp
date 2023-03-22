#include <iostream>
using namespace std;

int main()
{
    // signed char is 1 byte in size: 2^8 = 256 values
    // i.e. from -128 to 127

    // we assign the max value that fits in a char
    char value = 127;

    // output it (casting as int)
    cout << (int)value << endl;

    // incrementing gives no error
    value++;
    // it overflows to -128
    cout << (int)value << endl;

    return 0;
}