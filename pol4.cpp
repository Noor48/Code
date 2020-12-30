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

void rk4()
{
    ofstream fout("pol.dat");

    double x=1, v=1, x1=2, v1=1, x2=10, v2=3, k1, k2, k3, k4,l1,l2,l3,l4, s=0, h=0.01;

    for(double t0=0; t0<=10; t0+=h)
    {
        fout << t0 << "  ";
        
        for(double t=0; t<=t0; t+=h)
        {
            v += h*f2(t,x,v);
            x += h*f1(t,x,v);
        }

        fout << x << "  ";

        for(double t=0; t<=t0; t+=h)
        {
            v1 += h*f2(t,x1,v1);
            x1 += h*f1(t,x1,v1);
        }

        fout << x1 << "  ";

        for(double t=0; t<=t0; t+=h)
        {
            v2 += h*f2(t,x2,v2);
            x2 += h*f1(t,x2,v2);
        }
        
        fout << x2 << "  ";

        fout << endl;
    }
}

int main()
{
    rk4();

    return 0;
}