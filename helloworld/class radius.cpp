#include <iostream>
#include <string>
using namespace std;

class Circle
{
private:
    double radius;
    string color;

public:
    Circle(double r = 1.0, string c = "red")
    {
        radius = r;
        color = c;
    }

    double getRadius()
    {
        return radius;
    }

    string getColor()
    {
        return color;
    }

    double getArea()
    {
        return radius*radius*3.1416;
    }
};

int main()
{
    Circle c1(1.2, "blue");
    cout << "Radius = " << c1.getRadius() << " Area = " << c1.getArea() << " Color = " << c1.getColor() << endl;

    Circle c2(3.4);
    cout << "Radius = " << c2.getRadius() << " Area = " << c2.getArea() << " Color = " << c2.getColor() << endl;

    Circle c3;
    cout << "Radius = " << c3.getRadius() << " Area = " << c3.getArea() << " Color = " << c3.getColor() << endl;

    return 0;
}
