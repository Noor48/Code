#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double u)
{
    return cos((M_PI*pow(u,2))/2);
}

double f2(double u)
{
    return sin((M_PI*pow(u,2))/2);
}

double Fr_cos(double x)
{
    double a=0, b=x, n=100, I=0, J=0, K=0, A=0, h;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f1(a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f1(a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f1(a+i*h);
    }
    
    A =(3*h/8)*(f1(a) + 3*I + 3*J + 2*K + f1(b));
    return A;
}

double Fr_sin(double x)
{
    double a=0, b=x, n=100, I=0, J=0, K=0, A=0, h;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f2(a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f2(a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f2(a+i*h);
    }
    
    A =(3*h/8)*(f2(a) + 3*I + 3*J + 2*K + f2(b));
    return A;
}

double diffraction(double u0, double I0)
{
    return 0.5*I0*(pow(Fr_cos(u0)+0.5,2)+pow(Fr_sin(u0)+0.5,2));
}

int main()
{
    ofstream fout("fresnel7.dat");
    ofstream file("fresnel8.dat");
    for(double x=0; x<=4; x+=0.001)
    {
        fout << x << "  " << Fr_cos(x) << "  " << Fr_sin(x) << endl;
    }

    for(double u0=-1; u0<=4; u0+=0.001)
    {
        file << u0 << "  " << diffraction(u0, 5) << endl;
    }

    return 0;
}