#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return x*cos(x)-sin(x);
}

double d(double x)
{
    double h=0.001;
    return (f(x+h)-f(x-h))/(2*h);
}

double newton (double x)
{
    double h = f(x)/d(x);
    while(h>=0.000000001)
    {
        x -= h;
        h = f(x)/d(x);
        
    }

    return x;
}

int main()
{
    cout << newton(4) << endl;
    return 0;
}