#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return sin(x)-x*cos(x);
}

double df(double x)
{
    double h=0.0001;

    return (f(x+h)+f(x-h))/(2*h);
}

double newton(double x)
{
    double h = f(x)/df(x);

    while (abs(h) >= 0.0001)
    {
        x -= h;

        h = f(x)/df(x);
    }

    return x;
}

int main()
{
    cout << newton(4) << endl;

    return 0;
}