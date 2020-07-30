#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "this is a vehicle\n";
    }
};

class Fourwheeler: public Vehicle
{
public:
    Fourwheeler()
    {
        cout << "Objects with 4 wheels are vehicle\n";
    }
};

class Car: public Vehicle
{
public:

    Car()
    {
        cout << "Car has 4 wheels\n";
    }
};

int main()
{
    Car obj;
    return 0;
}
