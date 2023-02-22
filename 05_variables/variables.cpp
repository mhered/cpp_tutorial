// variables.cpp

#include <iostream>
#include <limits.h> // make accessible integer limits
#include <iomanip>  // I/O manipulation
using namespace std;

int main()
{

    // int
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Range int: [ " << INT_MIN << " , " << INT_MAX << " ]" << endl;
    int integer = 3170125794; // overflow error
    cout << "Integer: " << integer << endl
         << endl;

    // long
    cout << "Size of long int: " << sizeof(long) << " bytes" << endl;
    cout << "Range long int: [ " << LONG_MIN << " , " << LONG_MAX << " ]" << endl;
    long long_integer = 3170125794; // no overflow error
    cout << "Long Integer: " << long_integer << endl
         << endl;

    // short
    cout << "Size of short int: " << sizeof(short) << " bytes" << endl;
    cout << "Range short int: [ " << SHRT_MIN << " , " << SHRT_MAX << " ]" << endl;
    short short_integer = 25234; // no overflow error
    cout << "Short Integer: " << short_integer << endl
         << endl;

    // unsigned
    cout << "Size of unsigned int: " << sizeof(unsigned) << " bytes" << endl;
    cout << "Max unsigned int: " << UINT_MAX << endl;
    unsigned u_integer = 3170125794; // no overflow error
    cout << "Unsigned Integer: " << u_integer << endl
         << endl;

    // float
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    float float_value = 123.456789;
    // setprecision() changes the number of digits presented
    cout << setprecision(20) << "Float as fixed: " << fixed << float_value << endl;
    cout << "Float as scientific: " << scientific << float_value << endl
         << endl;

    // double
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    double double_value = 123.456789;
    cout << setprecision(20) << "Double as fixed: " << fixed << double_value << endl;
    cout << "Double as scientific: " << scientific << double_value << endl
         << endl;

    // long double
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    long double l_double_value = 123.456789;
    cout << setprecision(20) << "Long Double as fixed: " << fixed << l_double_value << endl;
    cout << "Long Double as scientific: " << scientific << l_double_value << endl
         << endl;

    // bool
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
    bool b_value = true;
    cout << b_value << endl;

    // char
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    char c_value_1 = 55; // this outputs ASCII 55 i.e. '7', check out https://en.wikipedia.org/wiki/ASCII
    cout << c_value_1 << endl;

    char c_value_2 = '7'; // you can also specifiy directly the character
    cout << c_value_2 << endl;
    cout << (int)c_value_2 << endl; // you can cast to the int value

    // wchar_t for unicode chars
    cout << "Size of char: " << sizeof(wchar_t) << " bytes" << endl;
    char wc_value = 'i';
    cout << wc_value << endl;

    return 0;
}