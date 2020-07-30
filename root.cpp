#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#define e 0.000001
using namespace std;

double f1(double x)
{
    return x-exp(x)-1;
}

double f2(double x)
{
    return cos(x)-x*exp(x);
}

double f3(double x)
{
    return x-exp(-x);
}

double f4(double x)
{
    return x*sin(x)+cos(x);
}

double bisection( double f(double x), double a, double b)
{
    double c=0;
    while (abs(a-b)>=e)
    {
        c = (a+b)/2;
        
        if (f(c)==0)
        {
            break;
        }

        else if(f(a)*f(c)<0)
        {
            b = c;
        }

        else 
        {
            a = c;
        }
        return c;
    }
}


double newton(double f(double x), double x)
{
    double h=0.001;
    double d = (f(x+h)-f(x-h))/(2*h);
    double h1 = f(x)/d;
    while (abs(h1)>=e)
    {
        x -= h;
        h1 = f(x)/d;
        return x;
    }
}

double secant(double f(double x))
{   
    double x, h=0.001;
    double d = (f(x+h)-f(x-h))/(2*h);

    return x;

}


int main()
{
    cout << bisection(f1,4,-2) << "    " << newton(f1,5) << endl;
    cout << bisection(f2,5,-3) << "    " << newton(f2,1) << endl;
    cout << bisection(f3,8,-5) << "    " << newton(f3,7) << endl;
    cout << bisection(f4,3,-1) << "    " << newton(f4,6) << endl;
    return 0; 
}