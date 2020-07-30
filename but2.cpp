#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double x, double y, double z)
{
    return 10*(y-x);
}

double f2(double t, double x, double y, double z)
{
    return x*(27-z)-y;
}

double f3(double t, double x, double y, double z)
{
    return x*y -(8/3)*z;
}

void diff(double x0, double y0, double z0)
{
    ofstream fout ("but2.dat");

    double x=x0, y=y0, z=z0, k1, k2, k3, k4, l1, l2, l3, l4, m1, m2, m3, m4, s=0, h=0.001;

    for(double t=0; t<=100; t+=h)
    {
        fout << t << "  " << x << "  " << y << "  " << z << "  " << endl;

        k1 = h*f1(t,x,y,z);
        l1 = h*f2(t,x,y,z);
        m1 = h*f3(t,x,y,z);
        k2 = h*f1(t+h/2, x+k1/2, y+l1/2, z+m1/2);
        l2 = h*f2(t+h/2, x+k1/2, y+l1/2, z+m1/2);
        m2 = h*f3(t+h/2, x+k1/2, y+l1/2, z+m1/2);
        k3 = h*f1(t+h/2, x+k2/2, y+l2/2, z+m2/2);
        l3 = h*f2(t+h/2, x+k2/2, y+l2/2, z+m2/2);
        m3 = h*f3(t+h/2, x+k2/2, y+l2/2, z+m2/2);
        k4 = h*f1(t+h, x+k3, y+l3, z+m3);
        l4 = h*f2(t+h, x+k3, y+l3, z+m3);
        m4 = h*f3(t+h, x+k3, y+l3, z+m3);
        
        x += (k1 + 2*k2 + 2*k3 + k4)/6;
        y += (l1 + 2*l2 + 2*l3 + l4)/6;
        z += (m1 + 2*m2 + 2*m3 + m4)/6;
    }
}

int main()
{
    diff(0,1,0);

    return 0;
}