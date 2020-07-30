#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double x, double v)
{
    return v;
}

double f2(double t, double x, double v)
{
    return (1-pow(x,2))*v-x;
}

void rk4(double x0, double v0, double t, double dt)
{
    ofstream fout("pol2.dat");

    double x=x0, v=v0, k1, k2, k3, k4,l1,l2,l3,l4, s=0, h=0.001;

    for(int i=0; i<=100; i++)
    {
        fout << t << "  " << x << "  " << v << endl;

        v -= dt*f2(t,x,v);
        x += dt*f1(t,x,v);
        t += dt;
    }
}

int main()
{
    rk4(1,1,0,0.001);
    return 0;
}