#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double A, double theta)
{
    return (A*cos(theta)+1)*sin(theta)/(pow((pow(A,2)+2*A*cos(theta)+1),2));
}

double scatt(double A)
{
    double a=0, b=M_PI, I=0, J=0, K=0, S=0, h, n=100;
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
    ofstream fout ("scat.dat");
    for(double x=0; x<=209)
}