#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x, double t)
{
    return (2*exp(-pow(t,2)))/(pow(M_PI,0.5));
}

double errint(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h;
    int n=100;
    h = (b-a)/n;
    for(int i=1; i<=n; i+=3)
    {
        I += f(x,a+i*h);
    }

    for(int i=2; i<=n; i+=3)
    {
        J += f(x,a+i*h);
    }
    
    for(int i=3; i<=n; i+=3)
    {
        K += f(x,a+i*h);
    }

    A = (3*h/8)*(f(x,a) + 3*I + 3*J + 2*K + f(x,b));
    return A;
}

int main()
{
    ofstream fout ("err2.dat");
    for(double x=-2; x<=2; x+=0.01)
    {
        fout << x << " " << errint(x) << endl;
    }

    return 0;
}