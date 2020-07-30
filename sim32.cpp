#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return exp(1/(1+pow(x,2)));
}

double sim3(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f(a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f(a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f(a+i*h);
    }
    
    A = (3*h/8)*(f(a) + 3*I + 3*J + 2*K + f(b));
    return A;
}

int main()
{
    ofstream fout ("sim32.dat");
    for(double x=-1; x<=1; x+=0.00001)
    {
        fout << x << " " << sim3(x)<< " " << f(x) << endl;
    }

    return 0;
}