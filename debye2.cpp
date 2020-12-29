#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x, double t)
{
    return 9*100*8.314*pow(t/428,3)*(pow(x,4)*exp(x)/pow((exp(x)-1),2));
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
    return n*(x*p(x,n)-p(x,n-1))/(pow(x,2)-1);
}

double g(double t)
{
    int n=20;
    double a=0, b=428/t, x0[n],x[n],w[n],xp[n],wp[n],c,h,s=0;

    for(int i=0; i<n; i++)
    {
        x0[i] = cos(M_PI* (i+1-0.25)/(n+0.5));
        c = x0[i];
        h = p(c,n)/dp(c,n);

        while(abs(h)>0.00001)
        {
            c -= h;
            h = p(c,n)/dp(c,n);
        }

        x[i] = c;
        w[i] = 2/((1-pow(c,2))*pow(dp(c,n),2));
    }

    for(int i=0; i<n; i++)
    {
        xp[i] = ((b-a)*x[i]+b+a)/2;
        wp[i] = (b-a)*w[i]/2;
    }

    for(int i=0; i<n; i++)
    {
        s += wp[i]*f(xp[i],t);
    }

    return s;
}

int main()
{
    ofstream fout("debye2.dat");
    for(double t=5; t<=500; t++)
    {
        fout << t << "  " << g(t) << endl;
    }

    return 0;
}