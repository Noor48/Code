#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double y)
{
    return 2-exp(-4*t)-2*y;
}

double f2(double t)
{
    return 1+0.5*exp(-4*t)-0.5*exp(-2*t);
}

void euler(double t0, double y0)
{
    ofstream fout("euler.dat");
    double y=y0, h=0.001;
    for(double t=t0; t<=10; t+=h)
    {
        fout << t << " " << y << " " << f2(t) << endl;
        y += h*f1(t,y);
    } 
}

int main()
{
    euler(1,0);
    return 0;
}