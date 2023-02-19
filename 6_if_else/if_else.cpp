// if_else.cpp

#include <iostream>
using namespace std;
int main()
{

    string password = "hello";
    cout << "Please enter your password: " << flush;

    string user_input; // declare variables when used
    cin >> user_input;
    // cout << "'" << user_input << "' -> " << flush;
    if (user_input == password)
    {
        cout << "Access granted." << endl;
        cout << "1.\tAdd new record" << endl;
        cout << "2.\tDelete record" << endl;
        cout << "3.\tView record" << endl;
        cout << "4.\tSearch record" << endl;
        cout << "5.\tQuit" << endl;

        int user_selection = 0;

        do
        {
            cout << "Enter your selection (1-5): " << flush;
            cin >> user_selection;
            if (0 < user_selection && user_selection < 3) // multiple conditionals
            {
                cout << "Insufficient privileges" << endl;
            }
            else if (2 < user_selection && user_selection < 5)
            {
                cout << "Executing..." << endl;
            }
            else if (user_selection == 5)
            {
                cout << "Quitting..." << endl;
            }
            else
            {
                cout << "Invalid selection: '" << user_selection << "'" << endl;
            }

        } while (user_selection != 5);
    }
    else
    {
        cout << "Access denied." << endl;
    }

    return 0;
}