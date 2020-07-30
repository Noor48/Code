#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x, double theta)
{
    return 4*(pow(0.0253,0.5))*pow(1-pow(sin(theta/2),2)*pow(sin(x),2), -0.5);
}

double sim3(double theta)
{
    double a=0, b=M_PI/2, n=100, I=0, J=0, K=0, A=0, h;
    h = (b-a)/n;

    for(int i=1; i<n; i+=3)
    {
        I += f(a+i*h, theta);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f(a+i*h, theta);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f(a+i*h, theta);
    }
    
    A = (3*h/8)*(f(a,theta) + 3*I + 3*J + 2*K + f(b, theta));
    return A;
}

int main()
{
    ofstream fout ("pen.dat");

    for(double theta=0; theta<=M_PI/2; theta+=0.0001)
    {
        fout << theta << "  " << sim3(theta) << endl;
    }

    return 0;
}