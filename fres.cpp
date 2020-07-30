#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t)
{
    return cos(M_PI*pow(t,2)/2);
}

double f2(double t)
{
    return sin(M_PI*pow(t,2)/2);
}

double Fr_cos(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h, n=100;
    h = (b-a)/n;

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

    A = (3*h/8)*(f1(a) + 3*I + 3*J + 2*K + f1(b));
    return A;
}

double Fr_sin(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h, n=100;
    h = (b-a)/n;

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

    A = (3*h/8)*(f2(a) + 3*I + 3*J + 2*K + f2(b));
    return A;
}

double u(double x)
{
    double lambda = 1, z=3;
    return x*pow(2/(lambda*z),0.5);
}

double diffraction(double x)
{
    return (pow(2*Fr_cos(u(x))+1,2)+pow(2*Fr_sin(u(x))+1,2))/8;
}

int main()
{
    ofstream fout ("fres.dat");
    ofstream file ("diff2.dat");
    for(double x=0; x<=6; x+=0.01)
    {
        fout << x << " " << Fr_cos(x) << " " << Fr_sin(x) << endl;
    }

    for(double x=-5; x<=5; x+=0.01)
    {
        file << x << " " << diffraction(x) << endl;
    }

    return 0;
}