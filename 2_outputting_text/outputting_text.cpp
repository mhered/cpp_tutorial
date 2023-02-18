//outputting_text.cpp

#include <iostream>
using namespace std;

int main() {

    int numberCats = 5; // declare an integer variable. Used camelCase for the name.
    int numberDogs = 3; // be consistent with naming convention, do not mix e.g. camelCase and snake_case

    cout << "Starting " << flush; //<< is insertion operator. flush to clean the buffer to guarantee it will print
    cout << "program... " << endl; //endl adds an endline and flushes the output
    cout << "Number of cats: " << numberCats << " cats. " <<endl; //can join several strings in one cout statement
    cout << "Number of dogs: " << numberDogs << " dogs. " <<endl; 
    cout << "Number of animals: " << numberCats + numberDogs << " dogs. " <<endl; //can 


    cout << "Bye!" << endl; 

    return 0;
}