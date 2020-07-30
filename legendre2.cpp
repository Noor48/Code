#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x, int n)
{
    if (n==0)
    {
        return 1;
    }

    else if (n==1)
    {
        return x;
    }

    else 
    {
        return ((2*n-1)*x*f(x,n-1)-(n-1)*f(x,n-2))/n;
    }
}

int main()
{
    ofstream fout ("leg2.dat");

    for (double x=-1; x<=1; x+=0.0001)
    {
        fout << x << "  " << f(x,0) << "  " << f(x,1) << "  " << f(x,2) << "  " << f(x,3) << "  " << f(x,4) << "  " <<  endl;
    }

    return 0;
}