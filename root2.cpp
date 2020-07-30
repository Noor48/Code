#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x,double n)
{
    return pow(x,2)-n;
}

double df(double x, double n)
{
    double h=0.001;
    return (f(x+h,n)-f(x-h,n))/(2*h);
}

double newton(double x,double n)
{
    double h=f(x,n)/df(x,n);
    while(abs(h)>=0.000000001)
    {
        x-= h;
        h=f(x,n)/df(x,n);
        return x;
    }
}

int main()
{
    cout << newton(13,292) << endl;

    return 0;
}