#include <iostream>
using namespace std;

class Base
{
public:

    void show()
    {
        cout << "Base Class" << endl;
    }
};

class Derived: public Base
{
public:

    void show()
    {
        cout << "Derived Class" << endl;
    }
};

int main()
{
    Base b;

    Derived d;

    b.show();

    d.show();

    return 0;
}
