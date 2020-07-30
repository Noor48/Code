#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double x, double y, double z)
{
    return 10*(y-x);
}

double f2(double x, double y, double z)
{
    return x*(27-z)-y;
}

double f3(double x, double y, double z)
{
    return (x*y)-((8/3)*z);
}

void rk4(double x0, double y0, double z0)
{
    double x=x0, y=y0, z=z0, k1, k2, k3, k4, l1, l2, l3, l4, m1, m2, m3, m4, h=0.0001;
    ofstream fout ("lor.dat");
    ofstream file ("lor2.dat");
    for(double t=0; t<=100; t+=h)
    {
        fout << t << " " << x << " " << y << " " << z << endl;
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);
        m1=h*f3(x,y,z);
        k2=h*f1(x+k1/2,y+l1/2,z+m1/2);
        l2=h*f2(x+k1/2,y+l1/2,z+m1/2);
        m2=h*f3(x+k1/2,y+l1/2,z+m1/2);
        k3=h*f1(x+k2/2,y+l2/2,z+m2/2);
        l3=h*f2(x+k2/2,y+l2/2,z+m2/2);
        m3=h*f3(x+k2/2,y+l2/2,z+m2/2);
        k4=h*f1(x+k3,y+l3,z+m3);
        l4=h*f2(x+k3,y+l3,z+m3);
        m4=h*f3(x+k3,y+l3,z+m3);
        x+= (k1+2*k2+2*k3+k4)/6;
        y+= (l1+2*l2+2*l3+l4)/6;
        z+= (m1+2*m2+2*m3+m4)/6;
    }

    for(double t=0; t<=100; t+=h)
    {
        file << t << " " << x << " " << y << " " << z << endl;
        x+=h*f1(x,y,z);
        y+=h*f2(x,y,z);
        z+=h*f3(x,y,z);
    }
}

int main()
{
    rk4(0,1,0);

    return 0;
}