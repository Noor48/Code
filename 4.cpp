#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double x)
{
    return -(1/tan(x));
}

double f2(double x)
{
    double k = 10.498597;
    return (1/x)*pow(k-pow(x,2),0.5);
}

double f(double x)
{
    return f1(x)-f2(x);
}

double df(double x)
{
    double h=0.0001;

    return (f(x+h)-f(x-h))/(2*h);
}

double newton(double x)
{
    double h = f(x)/df(x);

    while(abs(h)>=0.0001)
    {
        x -= h;
        h = f(x)/df(x);
    }

    return x;
}

int main()
{
    ofstream fout ("4.dat");

    for (double x=-20; x<=20; x+=0.0001)
    {
        fout << x << "  " << f1(x) << "  " << f2(x) << endl;
    }

    double x;
    cout << "Enter Initial Guess:   " << endl;
    cin >> x;
    cout << newton(x) << endl;

    return 0;
}