#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    double k=150, m=7.2;
    return (-k*x)/m;
}

void verlet()
{
    ofstream fout ("ver.dat");
    double x=0, v=1, h=0.001;
    for(double t=0; t<=10; t+=h)
    {
        double xold=x;
        fout << t << " " << x << " " <<  v << " " << endl;
        x+=h*v+ ((h*h)/2)*f(x);
        v+=((h/2)*(f(x)+f(xold)));
    }
}

int main()
{
    verlet();
    return 0;
}