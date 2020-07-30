#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    }
};

class FourWheeler
{
public:
    FourWheeler()
    {
        cout << "This is a 4 wheeler vehicle" << endl;
    }
};

class Car: public Vehicle, public FourWheeler
{
public:
    car()
    {
        cout << "Car class \n";
    }
};

int main()
{
    Car obj;
    return 0;
}
