#include <iostream>
using namespace std;

int main()
{
    int value1 = 8;
    int value2 = value1++; // postfix: value2 is assigned before value1 incremented: value2 = 8, value1 = 9
    cout << "Value1 is: " << value1 << endl;
    cout << "Value2 is: " << value2 << endl;

    int value3 = ++value1; // prefix: value3 assigned after value1 incremented: value3 = value1 = 10
    cout << "Value1 is: " << value1 << endl;
    cout << "Value3 is: " << value3 << endl;
}