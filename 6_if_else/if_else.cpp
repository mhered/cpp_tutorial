// if_else.cpp

#include<iostream>
using namespace std;
int main(){

    string password ="hello";
    cout << "Please enter your password: " << flush;
    
    string user_input; //declare variables when used
    cin >> user_input;
    // cout << "'" << user_input << "' -> " << flush;
    if(user_input == password){ 
        cout << "Access granted." << endl;
    } else {
        cout << "Access denied." << endl;
    }

    return 0;
}