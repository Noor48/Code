#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return 1/(1+sin(x));
}

double trap(double a, double b, int n)
{
    double x=0, sum=0, h;

    if(n==1)
    {
        return 0.5*(b-a)*(f(a)+f(b));
    }

    else
    {
        h=(b-a)/n;
        x = a+h;
        sum+=f(a);

        for(int i=1; i<n; i++)
        {
            sum += f(i);
            x += h;
        }

        sum += f(b);

        return 0.5*h*sum;
    }
}

double sim(double a, double b, int n)
{
    double I=0, J=0, K=0, A=0, h=(b-a)/n;

    for(int i=1; i<n; i+=2)
    {
        I += f(a+i*h);
    }

    for(int i=2; i<n; i+=2)
    {
        J += f(a+i*h);
    }
    
    A = (h/3)*(f(a) + 4*I + 2*J + f(b));
    return A;
}

double sim3(double a, double b, int n)
{
    double I=0, J=0, K=0, A=0, h;
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
    ofstream fout ("sim3.dat");
    double a=0, b=M_PI/2;
    int n = 100;
    for(double i=a; i<=b; i+=0.0001)
    {
        fout << i << " " << trap(i, b, n) << " " << sim(i, b ,n) << " " << sim3(i, b, n) << endl;
    }

    return 0;
}