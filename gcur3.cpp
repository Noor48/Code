#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double A, double x)
{
    return (1/pow(2*M_PI, 0.5))*exp(-pow(x,2)/2);
}

double sim3(double A)
{
    double a=-A, b=A, I=0, J=0, K=0, S=0, h, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f(A, a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f(A, a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f(A, a+i*h);
    }
    
    S = (3*h/8)*(f(A,a) + 3*I + 3*J + 2*K + f(A,b));
    return S;
}

int main()
{
    ofstream fout ("gcur.dat");
    for(double a=-2; a<=2; a+=0.0001)
    {
        fout << a << " " << sim3(a) << endl;
    }

    return 0;
}