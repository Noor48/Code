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

double f(double x, int n, double theta)
{
    return ((2*pow(x/2,n))/(pow(M_PI,0.5)*fact(n-0.5)))*cos(x*sin(theta))*pow(cos(theta),2*n);
}

double sim3(double x, int n)
{
    double a=0, b=M_PI/2, N=100, I=0, J=0, K=0, A=0, h;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f(x, n, a+i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f(x, n, a+i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f(x, n, a+i*h);
    }
    
    A = (3*h/8)*(f(x,n,a) + 3*I + 3*J + 2*K + f(x,n,b));
    return A; 
}

double ff(double x, double q)
{
    return 1-(1/2*2*M_PI*q)*(sim3(x,0));
}

double sim31(double q)
{
    double a=0, b=2*2*M_PI, N=100, I=0, J=0, K=0, A=0, h;
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
        K += ff(a+i*h,q);
    }
    
    A = (3*h/8)*(ff(a,q) + 3*I + 3*J + 2*K + ff(b,q));
    return A; 
}


int main()
{
    ofstream fout ("bessel8p10.dat");
    ofstream file ("trans.dat");

    for(double x=0; x<=25; x+=0.001)
    {
        fout << x << "  " << sim3(x,0) << "  " << sim3(x,1) << "  " << sim3(x,2) << "  " << sim3(x,3) << endl;
    }

    return 0;
}