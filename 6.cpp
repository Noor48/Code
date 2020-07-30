#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double v, double x,double f)
{
    return v;
}

double f2(double t, double v, double x, double f)
{
    double l=9.8, g=9.8, q=0.5, s=(2/3);

    return -q*v-f*sin(x*t)*s;
}

void euler (double v0, double x0)
{
    ofstream fout ("6x.dat");
    ofstream file ("6v.dat");

    double x=x0, x1=x0, x2=x0, v=v0, v1=v0, v2=v0, h=0.01;

    for(double t=0; t<=10; t+=h)
    {
        fout << t << "  " << x << "  " << x1 << "  " << x2 << endl;
        file << t << "  " << v << "  " << v1 << "  " << v2 << endl;
        
        x += h*f1(t,v,x,0);
        v += h*f2(t,v,x,0);
        x1 += h*f1(t,v1,x1,0.5);
        v1 += h*f2(t,v1,x1,0.5);
        x2 += h*f1(t,v2,x2,1.2);
        v2 += h*f2(t,v2,x2,1.2);
    }
}

int main()
{
    euler(1,0);

    return 0;
}