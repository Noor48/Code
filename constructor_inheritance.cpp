#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Non-param Base" <<endl;
    }

    Base(int x)
    {
        cout << "Param of Base: " << x << endl;
    }
};

class Derived: public Base
{
public:
    Derived()
    {
        cout << "Non-Param of derived" << endl;
    }

    Derived(int x, int a):Base(x)
    {
        cout << "Param of Derived: " << x << endl;
    }  
};

int main()
{
    Derived d;
    Derived d1(20,10);
    
}