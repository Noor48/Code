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

class Car: public Vehicle
{

};

class Bus: public Vehicle
{

};

int main()
{
    Car obj1;
    Bus obj2;
    return 0;
}
