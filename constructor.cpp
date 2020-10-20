#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:

    Rectangle()
    {
        length = 1;
        breadth = 1;
    }

    Rectangle(int l, int b)
    {
        setLength(l);
        setBreadth(b);
    }

    Rectangle (Rectangle &rec)
    {
        length = rec.length;
        breadth = rec.breadth;
    }
    
    void setLength(int l)
    {
        if(l>0)
        {
            length = l;
        }

        else
        {
            length = 0;
        }
    }

    void setBreadth(int b)
    {
        if(b>0)
        {
            breadth = b;
        }

        else
        {
            breadth = 0;
        }
    }

    int getLength()
    {
        return length;
    }

    int getBreadth()
    {
        return breadth;
    }

    int area()
    {
        return length*breadth;
    }

    int perimeter()
    {
        return 2*(length+breadth);
    }
};

int main()
{
    Rectangle r1;
    Rectangle r2(10,5);
    Rectangle r3(r2);
    
    cout << r1.area() << endl;
    cout << r1.perimeter() << endl;

    cout << r2.area() << endl;
    cout << r2.perimeter() << endl;
    
    cout << r3.area() << endl;
    cout << r3.perimeter() << endl;
    
    return 0;
}