#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#define e 0.0001
#define k 10.498597

double f1(double x)
{
    return (1/x)*sqrt(k-pow(x,2));
}

double f2(double x)
{
    return -(1/tan(x));
}

double f(double x)
{
    return -(1/tan(x))-(1/x)*sqrt(k-pow(x,2));
}

double df(double x)
{
    double h = 0.0001;
    return (f(x+h)+f(x-h))/(2*h);
}

double newton(double x)
{
    double h = f(x)/df(x);

    while (abs(h)>=0.001)
    {
        x -= h;
        h = f(x)/df(x);
    }

    return x;
}

int main()
{
    ofstream fout ("root7.dat");
    
    for (double x=-20; x<=20; x+=0.0001)
    {
        fout << x << "  " << f1(x) << "  " << f2(x) << endl;
    }

    return 0;
}