#include <iostream>
#include <cmath>
using namespace std;

double func(double x)
{
    return sin(x);
}

double diff(double x, double h)
{
    double dy = func(x + h) - func(x - h);

    return dy/2*h;
}

int main()
{
    cout << diff(1, 0.001);

    return 0;
}
