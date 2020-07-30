#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double vx, double vy)
{
    double q=1, m=1, E=1, B=2, y=0.5;
    return (q*B/m)*vy-(y/m)*vx+(q*E/m);
}

double f2(double vx, double vy)
{
    double q=1, m=1, E=1, B=2, y=0.5;
    return -(q*B/m)*vx-(y/m)*vy;
}

void euler (double vx0, double vy0)
{
    double vx=vx0, vy=vy0, h=0.00001;

    ofstream fout("elec.dat");

    for(double t=0; t<=10; t+=h)
    {
        fout << t << "  " << vx << "  " << vy << endl;

        vx += h*f1(vx,vy);
        vy += h*f2(vx,vy);
    }
}

int main()
{
    euler(4,0);
    return 0;
}