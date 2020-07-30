#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double v, double x, double y, double s)
{
    return v;
}

double f2(double v, double x, double y, double s)
{
    return -(2/x)*v-pow(y,s);
}

void astro(double x0, double y0, double v0, double t0)
{
    ofstream fout ("astro2.dat");
    double x=x0, y=y0, v=v0, t=t0, h=0.1;
    for(int s=0; s<=4; s++)
    {
        for(double x=0; x<=20; x+=h)
        {
            fout << x << " " << y << " " << v << endl;

            v+= h*f2(v,x,y,s);
            y+= h*f1(v,x,y,s);
        }
    }
}

int main()
{
    astro(1,1,1,1);
    return 0;
}