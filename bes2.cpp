#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(int n)
{
    if (n<=1)
    {
        return 1;
    }

    else 
    {
        return n*fact(n-1);
    }
}

double f(int n, double x, double theta)
{
    return (pow(x,n)/(pow(2,n+1)*fact(n)))*cos(x*cos(theta))*pow(sin(theta),2*n+1);
}

double bessel(int N, double x)
{
    double a=0, b=M_PI, I=0, J=0, K=0, A=0, h, n=100;
    h = (b-a)/n;

    for (int i=1; i<n; i+=3)
    {
        I += f(N,x,a + i*h);
    }

    for (int i=2; i<n; i+=3)
    {
        I += f(N,x,a + i*h);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += f(N,x,a + i*h);
    }

    A = (3*h/8)*(f(N,x,a) + 3*I + 3*J + 2*K + f(N,x, b));
    return A;
}

double f1(double r)
{
    return 1-pow(r,2);
}

double ff(double r, double u)
{
    return f1(r)*bessel(0,u*r)*r;
}

double ant_radiation(double u)
{
    double a=0, b=1, I=0, J=0, K=0, A=0, h, n=100;
    h = (b-a)/n;

    for (int i=1; i<n; i+=3)
    {
        I += ff(a + i*h,u);
    }

    for (int i=2; i<n; i+=3)
    {
        I += ff(a + i*h,u);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += ff(a + i*h,u);
    }

    A = (3*h/8)*(ff(a,u) + 3*I + 3*J + 2*K + ff(b,u));
    return A;
}


int main()
{
    ofstream fout ("bes3.dat");
    ofstream file ("rad.dat");
    for(double x=0; x<=25; x+=0.001)
    {
        fout << x << " " << bessel(0,x) << " " << bessel(1,x) << " " << bessel(2,x) << " " << bessel(3,x) << endl;
    }

    for(double u=0; u<=25; u+=0.001)
    {
        file << u << " " << ant_radiation(u) << endl;
    }
    return 0;
}