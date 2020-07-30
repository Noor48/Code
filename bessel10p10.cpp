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
    return (2*pow(x*0.5,n)/(pow(M_PI,0.5)*fact(n-0.5)))*cos(x*cos(theta))*pow(sin(theta),2*n+1);
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

double ff(double x, double q)
{
    return 1-(1/2*2*M_PI*q)*bessel(0,x);
}

double transmitted(double q)
{
    double a=0, b=2*2*M_PI, h, N=100, I=0, J=0, K=0, A=0;

    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += ff(a+i*h,q);
    }

    for(int i=2; i<N; i+=3)
    {
        J += ff(a+i*h,q);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += ff(a+i*h,1);
    }
    
    A = (3*h/8)*(ff(a,q) + 3*I + 3*J + 2*K + ff(b,q));
    return A;
}

int main()
{
    ofstream fout ("bessel10p10.dat");
    ofstream file ("bessel10p10t.dat");
    for (double x=0; x<=25; x+=0.0001)
    {
        fout << x << "  " << bessel(0,x) << "  " << bessel(1,x) << "  " << bessel(2,x) << "  " << bessel(3,x) << endl;
    }

    for(double q=0; q<=4; q+=0.0001)
    {
        file << q << "  " << transmitted(q) << endl;
    }

    return 0;
}