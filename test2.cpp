#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double x, double v, double t)
{
    return v;
}

double f2(double x, double v, double t)
{
    double g=9.8, L=9.8;
    return -(g/L)*x;
}

void eulercromer(double x0, double v0, double t0)
{
    ofstream fout ("test2.dat");
    ofstream file ("test22.dat");

    double x=x0, v=v0, h=0.01;

    for(double t=t0; t<=1000; t+=h)
    {
        v += h*f2(x,v,t);
        x += h*f1(x,v,t);

        fout << t << "  " << x << "  " << v << endl;

    }
}

int main()
{
    eulercromer(0,1,0);

    return 0;
}