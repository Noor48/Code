#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double V(double x)
{
    return pow(x,4);
}

double f(double x, double A)
{
    return pow(8,0.5)/(pow(V(x)-V(A),0.5));
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

double dp(double x,int n)
{
    return (n/(pow(x,2)-1))*(x*p(x,n)-p(x,n-1));
}

double t(double A)
{
    double a=0, b=A;
    int n = 20;
    double xD[n], x[n], w[n], x_prime[n], w_prime[n], c, h;

    for(int i=0; i<n; i++)
    {
        xD[i] = cos((M_PI*((i+1)-0.25))/(n+0.5));
        c = xD[i];
        h = p(c,n)/dp(c,n);

        while(abs(h)>=0.00000000001)
        {
            c -= h;
            h = p(c,n)/dp(c,n);
        }

        x[i] = c;
        w[i] = (2/(pow(c,2))*dp(c,n)*dp(c,n));
    }

    for (int i=0; i<n; i++)
    {
        x_prime[i] = 0.5*(((b-a)*x[i]) +(b+a));
        w_prime[i] = 0.5*(b-a)*w[i];
    }

    double result = 0;
    for(int i=0; i<n; i++)
    {
        result += w_prime[i]*f(x_prime[i],A);
    }

    return result;
}

int main()
{  
    ofstream fout ("t.dat");
    for(double A=0; A<2; A+=0.01)
    {
        fout << A << "  " << t(A) << endl;
    }

    return 0;
}