// switch.cpp

#include <iostream>
using namespace std;
int main()
{

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
        
        // input validation needed here

        switch(user_selection)
        {
            case 1: 
                cout << "Adding..." << endl;
                break;
            case 2:
                cout << "Deleting..." << endl;
                break;
            case 3:
                cout << "Viewing..." << endl;
                break;
            case 4:
                cout << "Searching..." << endl;
                break;
            case 5:
                cout << "Quitting..." << endl;
                break;
            default:
                cout << "Invalid selection: '" << user_selection << "'" << endl;
        }

    } while (user_selection != 5);
    
    return 0;
}