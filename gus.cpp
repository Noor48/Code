#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return (1/pow(2*M_PI, 0.5))*exp((-pow(x,2))/2);
}

double mygaussian(double a)
{
    double c=-a , b=a, I=0, J=0, K=0, A=0, h;
    int n=100;
    h = (b-c)/n;

    for (int i=1; i<n; i+=3)
    {
        I += f(a + i*h);
    }

    for (int i=2; i<n; i+=3)
    {
        J += f(a + i*h);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += f(a + i*h);
    }

    A = (3*h/8)*(f(a) + 3*I + 3*J + 2*K + f(b));
    return A;
}

int main()
{
    ofstream fout ("gus.dat");
    for (double a=-2; a<2; a+=0.001)
    {
        fout << a << " " << mygaussian(a) << endl;
    }

    return 0;
}