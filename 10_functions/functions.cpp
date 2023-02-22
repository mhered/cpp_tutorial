// switch.cpp

#include <iostream> // <> header file in std location

#include "utils.h" // "" header file in project folder

using namespace std;

int main()
{

    show_menu();
    int user_selection = 0;
    bool quit = false;

    do
    {
        user_selection = get_user_selection();
        quit = process_selection(user_selection);
    } while (!quit);

    return 0;
}


void show_menu()
{
    cout << "1.\tAdd new record" << endl;
    cout << "2.\tDelete record" << endl;
    cout << "3.\tView record" << endl;
    cout << "4.\tSearch record" << endl;
    cout << "5.\tQuit" << endl;
}

int get_user_selection()
{
    int user_selection = 0;

    do
    {
        cout << "Enter your selection (1-5): " << flush;
        cin >> user_selection;

        // better input validation needed here
        if (user_selection >= 1 && user_selection <= 5)
        {
            break;
        }
        cout << "Invalid selection '" << user_selection << "'" << endl;
    } while (true);

    return user_selection;
}

bool process_selection(int selection)
{
    switch (selection)
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
        return true;
    }
    return false;
}


