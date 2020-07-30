#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double n)
{
    return sqrt(n);
}

double df(double n)
{
    return 1/(2*sqrt(n));
} 

double bisection(double a, double b)
{
    double c=0;

    while (abs(a-b)>=0.0001)
    {
        c = (a+b)/2;

        if (f(c)==0)
        {
            break;
        }

        else if (f(a)*f(c)>=0)
        {
            b=c;
        }

        else 
        {
            a=c;
        }
    }

    return c;
}

double newton(double n)
{
    double h = f(n)/df(n);

    while (abs(h)>=0.0001)
    {
        n -= h;
        h = f(n)/df(n);
    }

    return n;
}

int main()
{
    cout << bisection(4,-2) << "   " << newton(29) << endl;

    return 0;
}