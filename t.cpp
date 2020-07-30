#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    }
};

class Fourwheeler
{
public:
    Fourwheeler()
    {
        cout << "It has four wheels" << endl;
    }
};

class Car : public Vehicle , public Fourwheeler
{
public:
    Car()
    {
        cout << "Car class" << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}
