#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(double n)
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

double gerf(double x, double n)
{
    double sum=0;

    for(int k=0; k<=n; k++)
    {
        sum += (pow(2,k)*pow(x,2*k+1))/(fact(2*k+1));
    }

    return sum*(2*exp(-pow(x,2))/pow(M_PI,0.5));
}

int main()
{
    ofstream fout ("err.dat");
    for(double x=-3; x<=3; x+=0.0001)
    {
        fout << x << " " << gerf(x,20) << endl;
    }

    return 0;
}