#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double t, double v)
{
    double g=9.8;

    return g-0.2*v;
}

void rk4(double t0, double v0)
{
    double v=v0, k1,k2,k3,k4,s=0, h=0.0001;
    ofstream fout ("ret2.dat");
    for(double t=t0; t<=100; t+=h)
    {
        fout << t << "  " << v << endl;

        k1 = h*f(t,v);
        k2 = h*f(t+h/2, v+k1/2);
        k3 = h*f(t+h/2, v+k2/2);
        k4 = h*f(t+h, v+k3);

        v += (k1 + 2*k2 + 2*k3 + k4)/6;
    }
}

int main()
{
    rk4(0,0);

    return 0;
}