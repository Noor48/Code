#include <iostream>
using namespace std;

class Vehicle3
{
public:
    Vehicle3()
    {
        cout << "This is a Vehicle" << endl;
    }
};

class Fare
{
public:
    Fare()
    {
        cout << "Fare of Vehicle" << endl;
    }
};

class Car: public Vehicle3
{

};

class Bus: public Vehicle3, public Fare
{

};

int main()
{
    Bus obj2;
    return 0;
}
