#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double theta, double A)
{
    return 0.5*(sin(theta)*(A*cos(theta)+1)/(pow((pow(A,2)+2*A*cos(theta)+1),2)));
}

double sim3(double A)
{
    double a=0, b=M_PI, h, B=0, I=0, J=0, K=0;
    int n=100;
    h = (b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f(a + i*h,A);
    }

    for(int i=1; i<n; i+=3)
    {
        I += f(a + i*h,A);
    }
    
    for(int i=1; i<n; i+=3)
    {
        K += f(a + i*h,A);
    }
    
    B = (3*h/8)*(f(a,A) + 3*I + 3*J + 2*K + f(b,A));
    return B;
}

int main()
{
    ofstream fout ("angle.dat");
    for(double A=2; A<=20; A+=0.01)
    {
        fout << A << " " << sim3(A) << endl;
    }

    return 0;
}