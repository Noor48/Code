#include <iostream>
using namespace std;

class Car
{
public:
    virtual void start()
    {
        cout << "Car started" << endl;
    }

    virtual void stop()
    {
        cout << "Car stopped" << endl;
    }
};

class Innova : public Car 
{
public:
    void start()
    {
        cout << "Innova started" << endl;
    }

    void stop()
    {
        cout << "Innova stopped" << endl;
    }
};

class Swift : public Car 
{
    void start()
    {
        cout << "Swift started" << endl;
    }

    void stop()
    {
        cout << "Swift stopped" << endl;
    }
};

int main()
{
    Car *c = new Innova();
    c->start();
    c->stop();
    
    c = new Swift();
    c->start();
    c->stop();
    return 0;
}