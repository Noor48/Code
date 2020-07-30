#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double x)
{
    return x*exp(x)-1;
}

double bisection(double a, double b)
{
    double c=0;
    while (abs(a-b)>=0.0001)
    {
        c = (a+b)/2;

        if (f1(c)==0)
        {
            break;
        }

        else if (f1(a)*f1(c)<0)
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

double df1(double x)
{
    return exp(x)*(1+x);
}

double diff(double x)
{
    double h=0.00001;
    
    return (f1(x+h)-f1(x-h))/(2*h);
}

double newton (double x)
{
    double h = f1(x)/diff(x);

    while (abs(h)>=0.0001)
    {
        h = f1(x)/diff(x);
        x -= h;
    }

    return x;
}

int main()
{
    cout << bisection(4,-2) << "  " << newton(5) << endl;

    return 0;
}
