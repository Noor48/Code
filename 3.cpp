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

void lane_emden(double v0, double y0)
{
    ofstream fout ("3.dat");

    double v, y, h=0.01;

    for (double x0=1; x0<=20; x0+=h)
    {
        fout << x0 << "  ";

        for (double s=0; s<=4; s++)
        {
            v=v0;
            y=y0;

            for (double x=1; x<=x0; x+=h)
            {
                v += h*f2(v,x,y,s);
                y += h*f1(v,x,y,s);
            }
            
            fout << y << "  ";
        }

        fout << endl;
    }
}

int main()
{
    lane_emden(0,1);

    return 0;
}