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

double g1(double x, int n)
{
    double s, sum=0;
    for(int i=0; i<=n-1; i++)
    {
        sum += pow(x,i)/fact(i);
    }
    return fact(n-1)*(1-exp(-x)*sum);
}

double g2(double x, int n)
{
    double sum=0; 
    for(int i=0; i<=n-1; i++)
    {
        sum += pow(x,i)/fact(i);
    }

    return fact(n-1)*(exp(-x)*sum);
}

double potential(double r)
{
    return ((1/2*r)*g1(2*r,3)+g2(2*r,2));
}

int main()
{
    ofstream fout ("pot.dat");
    for(double r=0; r<=4; r+=0.001)
    {
        fout << r << " " << potential(r) << endl;
    }

    return 0;
}