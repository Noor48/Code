#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1 (double x)
{
    return 1/(1+sin(x));
}

double trap(double a, double b, double n)
{
    double x = 0.0, sum = 0.0, h = 0.0;
    int i;
    
    if (n==1)
    {
        return 0.5*(b-a)*(f1(a) + f1(b));
    }

    else
    {
        h = (b-a)/n;
        sum += f1(a);
        x = a+h;
        for(i=1; i<n; i++)
        {
            sum += 2*f1(x);
            x += h;
        }

        sum += f1(b);

        return 0.5*h*sum;
    }
}

double sim(double a, double b, int n)
{
    int i;
    double I=0, J=0;
    double h = (b-a)/n;
    for(i=1; i<n; i+=2)
    {
        I += f1(a + i*h);
    }

    for(i=2; i<n; i+=2)
    {
        J += f1(a + i*h);
    }

    double A = (h/3)*(f1(a) + 4*I + 2*J + f1(b));

    return A;
}

double sim3(double a, double b, int n)
{
    double h=(b-a)/n, I=0, J=0, K=0, L;
    for(int i=1; i<n; i+=3)
    {
        I += f1(a + i*h);
    }

    for(int i=2; i<n; i+=3)
    {
        J += f1(a + i*h);
    }
    
    for(int i=3; i<n; i+=3)
    {
        K += f1(a + i*h);
    }
    
    L = (3*h/8)*(f1(a) + 3*I + 3*J + 2*K + f1(b));
    return L;
}

int main()
{
    ofstream fout ("test.dat");
    double a=0, b=M_PI/2;
    int n=120;
    for (double i=a; i<=b; i+= 0.001)
    {
        fout << i <<  "  " <<  trap(i, b, n) << "  " << sim(i, b, n)<< "  " << sim3(i, b, n) << endl;
    }

    return 0;

}