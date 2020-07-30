#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(int n, double x, double theta)
{
    return (1/M_PI)*cos(n*theta-x*sin(theta));
}

double bessel(int n, double x)
{
    double a=0, b=M_PI, h, N=100, I=0, J=0, K=0, A=0;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f(n,x,a+i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f(n,x,a+i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f(n,x,a+i*h);
    }
    
    A = (3*h/8)*(f(n,x,a) + 3*I + 3*J + 2*K + f(n,x,b));
    return A;
}

double mycos(double x)
{
    double s=0;
    for(double n=1; n<=20; n++)
    {
        s += 2*pow(-1,n)*bessel(2*n,x);
    }

    return bessel(0,x) + s;
}

int main()
{
    ofstream fout ("5.dat");
    ofstream file ("5c.dat");

    for(double x=0; x<=25; x+=0.0001)
    {
        fout << x << "  " << bessel(0,x) << "  " << bessel(1,x) << "  " << bessel(2,x) << "  " << bessel(3,x) << "  " << bessel(4,x) << endl;
    }

    for(double x=-M_PI; x<=M_PI; x+=0.01)
    {
        file << x << "  " << mycos(x) << "  " << cos(x) << endl;
    }
    return 0;
}