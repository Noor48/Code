#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double u, double t)
{
    return cos(M_PI*pow(t,2)/2);
}

double f2(double u, double t)
{
    return sin(M_PI*pow(t,2)/2);
}

double Fr_cos(double u)
{
    double a=0, b=u, I=0, J=0, K=0, A=0, h, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f1(u,a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f1(u,a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f1(u,a+i*h);
    }

    A = (3*h/8)*(f1(u,a) + 3*I + 3*J + 2*K + f1(u,b));
    return A;
}

double Fr_sin(double u)
{
    double a=0, b=u, I=0, J=0, K=0, A=0, h, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f2(u,a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f2(u,a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f2(u,a+i*h);
    }

    A = (3*h/8)*(f2(u,a) + 3*I + 3*J + 2*K + f2(u,b));
    return A;
}
double u(double x)
{
    return x*pow(2/3,0.5);
}
double diffraction (double x)
{
    return (pow(2*Fr_cos(u(x))+1,2) + pow(Fr_sin(u(x))+1,2))/8;
}

int main()
{
    ofstream fout ("int.dat");
    for(double x=-5; x<=2; x+=0.0001)
    {
        fout << x << " " << diffraction(x) << endl;
    }

    return 0;
}