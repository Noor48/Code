#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    return pow(x,3);
}

double pn(double x, int n)
{
    if(n==0)
    {
        return 1;
    }

    else if (n==1)
    {
        return x;
    }

    else
    {
        return (((2*n-1)*x*pn(x,n-1))-((n-1)*pn(x,n-2)))/n;
    }
}

double d_pn(double x, int n)
{
    return (n/((x*x)-1))*(x*pn(x,n)-pn(x,n-1));
}

double gauss_qua(double a, double b, int n)
{
    double res =0;
    if (n<=0)
    {
        cout << "The number of sample points can't be negetive or zero";
    }
    else
    {
        double x0[n],x[n],w[n],x_prime[n],w_prime[n],c,h;
        int i;
        for(i=0; i<n;i++)
        {
            x0[i]=cos((M_PI*((i+1)-0.25))/(n+0.5));
            c=x0[i];
        
            h=pn(c,n)/d_pn(c,n);
            while (abs(h)>=0.000000001)
            {
                c-=h;
                h = pn(c,n)/d_pn(c,n);
            } 

            cout << c << endl;
            x[i]=c;
            w[i]=(2/((1-c*c)*(d_pn(c,n)*d_pn(c,n))));
        }

        for (i=0; i<n; i++)
        {
            x_prime[i]=0.5*(((b-a)*x[i])+(b+a));
            w_prime[i]=0.5*(b-a)*w[i];
        }

        double res =0;
        for (i=0; i<n; i++)
        {
            res+=(w_prime[i]*f(x_prime[i]));
        }
    }
        return res;
}   

int main()
{
    double a, b;
    int n;
    cout << "Enter the lower limit: " << endl;
    cin >> a;
    cout << "Enter the higher limit: " << endl;
    cin >> b;
    cout << "Enter the order of n for legendre polynomial: " << endl;
    cin >> n;
    gauss_qua(a,b,n);
    return 0;
}