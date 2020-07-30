#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double t)
{
    return (2/pow(M_PI,0.5))*exp(-pow(t,2));
}

double errint(double x)
{
    double a=0, b=x, h, n=100, I=0, J=0, K=0, A=0;
    h = (b-a)/n;
    
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
    ofstream fout ("gauss2p7.dat");

    for(double x=-2; x<=2; x+=0.01)
    {
        fout << x << "  " << errint(x) << endl;
    }

    return 0;
}