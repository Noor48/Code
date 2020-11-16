#include <iostream>
using namespace std;

class Rectangle
{
public:
    void area()
    {
        cout << "Area of a Rectangle" << endl;
    }
};

class Cuboid : public Rectangle
{
public:
    void volume()
    {
        cout << "Volume of a Cuboid" << endl;
    }
};

int main()
{
    Cuboid c;
    Rectangle *p = &c;

    p->area();

    return 0;
}