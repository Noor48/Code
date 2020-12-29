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
    ofstream fout ("pol3.dat");
    double x=1, v=1,x1=2,v1=1, x2=10, v2=3, h=0.0001;
    
    for(double t=0; t<=100; t+=h)
    {
        fout << t << "  " << x << "  " << x1 << "  " << x2 << endl;

        x += h*f1(t,x,v);
        v += h*f2(t,x,v);
        x1 += h*f1(t,x1,v1);
        v1 += h*f2(t,x1,v1);
        x2 += h*f1(t,x2,v2);
        v2 += h*f2(t,x2,v2);
    }   
}

int main()
{
    rk4();

    return 0;
}