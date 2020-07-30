#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double x, double u)
{
    return sin(M_PI*pow(u,2)/2);
}

double f2(double x, double u)
{
    return cos(M_PI*pow(u,2)/2);
}

double Fr_sin(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h=0, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f1(x, a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f1(x, a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f1(x, a+i*h);
    }
    
    A = (3*h/8)*(f1(x,a) + 3*I + 3*J + 2*K + f1(x,b));
    return A;
}

double Fr_cos(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h=0, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f2(x, a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f2(x, a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f2(x, a+i*h);
    }
    
    A = (3*h/8)*(f2(x,a) + 3*I + 3*J + 2*K + f2(x,b));
    return A;
}

double diffraction(double I0, double u0)
{
    return 0.5*I0*(pow((Fr_cos(u0)+0.5),2)+(pow((Fr_sin(u0)+0.5),2)));
}

int main()
{
    ofstream fout ("fres2.dat");
    for(double x=0; x<=5; x+=0.0001)
    {
        fout << x << " " << Fr_sin(x) << " " << Fr_cos(x) << endl; 
    }

    ofstream file ("diff3.dat");
    for(double u0=-1; u0<=5; u0+=0.0001)
    {
        file << u0 << " " << diffraction(5,u0) << endl;
    }

    return 0;
}