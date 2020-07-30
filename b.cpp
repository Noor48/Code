#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(int n)
{
    if (n==1)
    {
        return 1;
    }

    else
    {
        return n*fact(n-1);
    }
}

double f(int n, double z, double theta)
{
}

double bessel(int n , double z)
{
    double a=0, b=M_PI, h, A=0;
    int N=100;
    h = (b-a)/n;
    for (int i=1; i<N; i++)
    {
        A += f(n, z, a+i*h);
    }

    return (h/2)*(f(n, z, a) + 2*A + f(n, z, b));
}

int main()
{
    ofstream fout ("pdf.dat");
    for (double z=0; z<25; z+=0.01)
    {
        fout << z << " " << bessel(0,1) << " " << " " << bessel(1,z) << " " << bessel(2,z) << " " << bessel(3,z) << endl;
    }

    return 0;
}