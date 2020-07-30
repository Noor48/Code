#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double t, double v)
{
    double g=9.8, a=0.2;
    return g-a*v;
}

void vel(double t0, double v0)
{
    double v=v0, t=t0, k1, k2, k3, k4, s=0, h=0.001;
    ofstream fout ("ret.dat");
    for(t=t0; t<=100; t+=h)
    {
        fout << t << " " << v << endl;

        k1 = h*f(t,v);
        k2 = h*f(t+h/2, v+k1/2);
        k3 = h*f(t+h/2, v+k2/2);
        k3 = h*f(t+h, v+k3);
        
        v += (k1 + 2*k2 + 2*k3 + k4)/6;
    }
}

int main()
{
    vel(0,0);
    return 0;
}