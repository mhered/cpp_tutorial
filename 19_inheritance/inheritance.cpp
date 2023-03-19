// inheritance.cpp

#include <iostream>
using namespace std;

// a little class hierarchy Machine -> Vehicle -> Car

class Machine
{
private: // private data
    int id;

private: // private methods
    int get_id() { return id; }

public:
    Machine() : id(0) { cout << "Machine constructor called with no args" << endl; }
    Machine(int id) : id(id) { cout << "Machine constructor called with id = " << id << endl; }
    void start() { cout << "Machine is Starting" << endl; }
    void info() { cout << "Machine ID: " << get_id() << endl; }
};

class Vehicle : public Machine
{
public:
    Vehicle() { cout << "Vehicle constructor called with no args" << endl; }

    // we can specify which constructor from the direct superclass to run and pass it parameters
    Vehicle(int id) : Machine(id) { cout << "Vehicle constructor called with id = " << id << endl; }
    void steer() { cout << "Vehicle is Steering" << endl; }
};

class Car : public Vehicle
{
public:
    Car() { cout << "Car constructor called with no args" << endl; }
    void warning() { cout << "Car is starting Warning lights" << endl; }
};

int main()
{
    Machine machine(123);
    machine.start();
    machine.info();
    // cout << machine.get_name() << endl; // this does not work because get_name is private

    Vehicle vehicle(246);
    vehicle.start();
    vehicle.steer();
    vehicle.info();

    Car car;
    car.start();
    car.steer();
    car.warning();
    car.info();

    return 0;
}