#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double y)
{
    return t*pow(y,0.5);
}

double f2(double t)
{
    return pow(pow(t,2)+4,2)/16;
}

void rk(double t0, double y0)
{
    double k1, k2, k3, k4, y=y0, h=0.001, s=0;

    ofstream fout ("rk4.dat");

    for(double t=t0; t<=10; t+=h)
    {
        fout << t << " " << y << " " << f2(t) << endl;

        k1 = h*f1(t, y);
        k2 = h*f1(t + h/2, y + k1/2);
        k3 = h*f1(t + h/2, y + k2/2);
        k4 = h*f1(t+h, y+k3);

        y += (k1 + 2*k2 + 2*k3 + k4)/6;
    }
}

int main()
{
    rk(0,1);
    return 0;
}