#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(int n)
{
    if(n<=1)
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
    return (2*pow(x/2,n)/(pow(M_PI,0.5)*fact(n-0.5)))*cos(x*sin(theta))*pow(cos(theta),2*n); 
}

double bessel(int n , double x)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0, h, N=100;
    h=(b-a)/N;

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

double f2(double q, double x)
{
    double k = 2*M_PI;
    return 1-bessel(0,x)/2*k*q;
}

double trans(double q)
{
    double a=0, b=2*M_PI*q, I=0, J=0, K=0, A=0, h, N=100;
    h=(b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f2(q,a+i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f2(q,a+i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f2(q,a+i*h);
    }

    A = (3*h/8)*(f2(q,a) + 3*I + 3*J + 2*K + f2(q,b));
    return A;
}


int main()
{
    ofstream file ("trans2.dat");
    ofstream fout ("bes6.dat");
    for(double x=0; x<=25; x+=0.0001)
    {
        fout << x << " " << bessel(0,x) << " " << bessel(1,x) << " " << bessel(2,x) << " " << bessel(3,x) << endl;
    }

    for(double q=0; q<=4; q+=0.001)
    {
        file << q  << " " << trans(q) << endl;
    }

    return 0;
}