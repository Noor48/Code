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

double sim3(int n, double x)
{
    double a=0, b=M_PI, N=100, h, I=0, J=0, K=0, A=0;
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

double f2(double r)
{
    return 1-pow(r,2);
}

double ff(double r, double u)
{
    return f2(r)*sim3(0,u*r)*r;
}

double rad(double u)
{
    double a=0, b=1, N=100, h, I=0, J=0, K=0, A=0;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += ff(a+i*h,u);
    }

    for(int i=2; i<N; i+=3)
    {
        J += ff(a+i*h,u);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += ff(a+i*h,u);
    }
    
    A = (3*h/8)*(ff(a,u) + 3*I + 3*J + 2*K + ff(b,u));
    return A;
}

int main()
{
    ofstream fout ("2.dat");
    ofstream file ("2r.dat");

    for(double x=0; x<=25; x+=0.0001)
    {
        fout << x << "  " << sim3(0,x) << "  " << sim3(1,x) << "  " << sim3(2,x) << "  " << sim3(3,x) << "  " << sim3(4,x) << endl;
    }

    for(double u=0; u<=25; u+=0.01)
    {
        file << u << "  " << rad(u) << endl;
    }

    return 0;
}