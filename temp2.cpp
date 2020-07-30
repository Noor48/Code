#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double t, double tau)
{
    return 100*(1-(2/pow(M_PI,0.5)*(exp(-pow(tau,2)))));
}

double simp3(double t)
{
    double a=0, b=8/pow(t,0.5), h, n=100, I=0, J=0, K=0, A=0;

    h = (b-a)/n;

    for (int i=1; i<n; i+=3)
    {
        I += f(t, a+i*h);
    }

    for (int i=2; i<n; i+=3)
    {
        J += f(t, a+i*h);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += f(t, a+i*h);
    }
    
    A = (3*h/8)*(f(t,a) + 3*I + 3*J + 2*K + f(t,b));

    return A;
}

int main()
{
    ofstream fout ("tem2.dat");

    for(double t=10; t<=200; t+=0.01)
    {
        fout << t << "  " << simp3(t) << endl;
    }

    return 0;
}