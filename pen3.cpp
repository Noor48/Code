#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double theta, double phi)
{
    double l=1, g=9.8;
    return (4*pow(0.0253,0.5))*pow(1-pow(sin(theta/2),2)*pow(sin(phi),2),-0.5);
}

double sim3(double theta)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0, h, n=100;
    h=(b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f(theta, a+i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f(theta, a+i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f(theta, a+i*h);
    }
    
    A = (3*h/8)*(f(theta,a) + 3*I + 3*J + 2*K + f(theta,b));
    return A;
}

int main()
{
    ofstream fout ("pen2.dat");
    for(double x=0; x<=M_PI/2; x+=0.0001)
    {
        fout << x << " " << sim3(x) << endl;
    }

    return 0;
}