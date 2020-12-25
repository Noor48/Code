#include <iostream>
using namespace std;

class BasicCar
{
public:
    virtual void start()
    {
        cout << "BasicCar started" << endl;
    }
};

class AdvancedCar : public BasicCar
{
public:
    void start()
    {
        cout << "AdvancedCar started" << endl;
    }
};

int main()
{
    BasicCar *p = new AdvancedCar();
    p->start();

    return 0;
}