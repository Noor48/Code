#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(int n)
{
    if (n<=1)
    {
        return 1;
    }

    else 
    {
        return n*fact(n-1);
    }
}

double ber(int n)
{
    double s=0;

    for(int p=1; p<=20; p++)
    {
        s += pow(p,-2*n);
    }

    return pow(-1,n-1)*2*fact(2*n)*s/(pow(2*M_PI,2*n));
}

double mytan(double x, int n)
{
    double s=0;

    for(int i=0; i<=n; i++)
    {
        s += (pow(-1, i-1)*pow(2,2*i)*(pow(2,2*i)-1)*ber(i)*pow(x,2*i-1))/fact(2*i);
    }

    return s;
}

int main()
{
    ofstream fout ("ber2.dat");

    for(double x=-M_PI/3; x<=M_PI/3; x+=0.0001)
    {
        fout << x << "  " << mytan(x,20) << " " << tan(x) << endl; 
    }

    return 0;
}