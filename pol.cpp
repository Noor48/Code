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

void rk4(double x0, double v0)
{
    ofstream fout("pol.dat");

    double x=x0, v=v0, k1, k2, k3, k4,l1,l2,l3,l4, s=0, h=0.001;

    for(double t=0; t<=100; t+=h)
    {
        fout << t << "  " << x << "  " << v << endl;

        k1 = h*f1(t,x,v);
        l1 = h*f2(t,x,v);
        k2 = h*f1(t+h/2, x+k1/2, v+l1/2);
        l2 = h*f2(t+h/2, x+k1/2, v+l1/2);
        k3 = h*f1(t+h/2, x+k2/2, v+l2/2);
        l3 = h*f2(t+h/2, x+k2/2, v+l2/2);
        k4 = h*f1(t+h/2, x+k1/2, v+l1/2);
        l4 = h*f2(t+h, x+k3, v+l3);
        
        x += (k1 + 2*k2 + 2*k3 + k4)/6;
        v += (l1 + 2*l2 + 2*l3 + l4)/6;
    }
}

int main()
{
    rk4(1,1);
    rk4(2,1);
    rk4(10,3);

    return 0;
}