// input.cpp

#include<iostream>
using namespace std;
int main(){

    cout << "Please enter your name: " << flush;
    string user_name; // declare variable
    cin >> user_name; // use cin and extraction operator >> to request input and save it in 
    cout << "Hello " << user_name << "!" << endl;

    cout << "Please enter your age: " << flush;
    int user_age;
    cin >> user_age;
    cout << "Looking great for a " << user_age << "-year-old!" << endl;
    
    return 0;
}