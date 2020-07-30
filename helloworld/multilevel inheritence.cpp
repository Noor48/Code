#include <iostream>
#include <string>
using namespace std;

class Vehicle2
{
public:
    Vehicle2()
    {
        cout << "This is a vehicle" << endl;
    }
};

class fourWheeler: public Vehicle2
{
public:
    fourWheeler()
    {
        cout << "Objects with 4 wheels are vehicles" << endl;
    }
};

class Car: public fourWheeler
{
public:
    Car()
    {
        cout << "Car has 4 wheels" << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}
