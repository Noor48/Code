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
    double a = pow(x/2,n)*cos(x*sin(theta))*pow(cos(theta),2*n);
    double b = 2/(pow(M_PI,2)*fact(n-0.5));
    return a*b;
}

double bessel (int n, double x)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0, h, N=100;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f(N, x, a+i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f(N, x, a+i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f(N, x, a+i*h);
    }
    
    A = (3*h/8)*(f(N,x,a) + 3*I + 3*J + 2*K + f(N,x,b));
    return A;
}

double f1(double q, double x)
{
    double k;
    return 1-bessel(0,x)/2*k*q;
}

double transmitted (double q)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0, h, N=100;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f1(q,a+i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f1(q,a+i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f1(q,a+i*h);
    }
    
    A = (3*h/8)*(f1(q,a) + 3*I + 3*J + 2*K + f1(q,b));
    return A;
}


int main()
{
    ofstream fout ("bes.dat");
    ofstream file ("trans.dat");
    for (double x=0; x<=25; x+=0.001)
    {
        fout << x << " " << bessel(0,x) << " " << bessel(1,x) << " " << bessel(2,x) << " " << bessel(3,x) << endl;
    }
    
    for (double q=0; q<=4; q+=0.01)
    {
        file << q << " " << transmitted(q) << endl;
    }
    

    return 0;
}