// loops.cpp

#include <iostream>
using namespace std;
int main()
{
    const int MAX = 1;
    const string PWD = "hello";
    
    int i = 0;
    cout << endl; 
    while (i < MAX)
    {
        cout << "While loop " << i++ << endl; // i++ increments after executing the line, ++i before.  
    };

    int j = 0;
    cout << endl;

    do // do-while always executes at least once (even if MAX == 0)
    {
        cout << "Do-While loop " << j++ << endl;
    } while (j < MAX); 

    return 0;
}