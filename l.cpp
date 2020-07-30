#include <iostream>
using namespace std;

class Vehicle2
{
public:
    Vehicle2()
    {
        cout << "This is a Vehicle " << endl;
    }
};

class Fourwheeler: public Vehicle2
{
public:
    Fourwheeler()
    {
        cout << "Object has 4 wheels " << endl;
    }
};

class Car : public Fourwheeler
{
public:
    Car()
    {
        cout << "Car has 4 wheels " << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}

