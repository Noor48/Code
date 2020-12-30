#include <iostream>
#include <cmath>
#include <fstraeam>
using namespace std;

double V(double x)
{
    return pow(x,4);
}

double f(double x, double A)
{
    return pow(8,0.5)/pow(V(A)-V(x),0.5);
}

double p(double x, int n)
{
    if(n==0)
    {
        return 1;
    }

    else if(n==1)
    {
        return x;
    }

    else 
    {
        return ((2*n-1)*x*p(x,n-1)-(n-1)*p(x,n-2))/n;
    }
}

double dp(double x, int n)
{
    return (n/(pow(x,2)-1))*(x*p(x,n)-p(x,n-1));
}

