#include <iostream>
#include <cmath>
#include <fstream>
#define V pow(10,-3)
#define rho 6.022*pow(10,28)
#define KB 1.38*pow(10,-23)
#define theta_D 428
using namespace std;

double debye(double x, double T)
{
    return 9*V*rho*KB*pow(T/theta_D,3)*((pow(x,4)*exp(x))/(pow(exp(x)-1,2)));
}

double Pn(double x, int n)
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
        return ((2*n-1)*x*Pn(x,n-1)-(n-1)*Pn(x,n-2))/n;
    }
}

double d_Pn(double x, int n)
{
    return (n/(pow(x,2)-1))*(x*Pn(x,n)-Pn(x,n-1));
}

double sp_heat(double T)
{
    double a=0, b=theta_D/T, result = 0;
    int n=6;
    if(n<=0)
    {
        cout << "The number of sample points can not be ngetive or zero";
    }
    else
    {
        double xD[n], x[n], w[n], x_prime[n], w_prime[n],c,h;
        int i;
        for(int i=0; i<n; i++)
        {
            xD[i] = cos((M_PI*((i+1)-0.25))/(n+0.5));
            c = xD[i];
            h = Pn(c,n)/d_Pn(c,n);
            while (abs(h)>=0.00000000001)
            {
                c -= h;
                h = Pn(c,n)/d_Pn(c,n);
            }

            x[i] = c;

            w[i] = (2/((1-pow(c,2))*(d_Pn(c,n)*d_Pn(c,n))));
        }

        for(int i=0; i<n; i++)
        {
            x_prime[i] = 0.5*((b-a)*x[i]+b+a);
            w_prime[i] = 0.5*(b-a)*w[i];
        }

        for(int i=0; i<n; i++)
        {
            result += (w_prime[i]*debye(x_prime[i], T));
        }
    }
    
    return result;
}

int main()
{
    ofstream fout ("debye.dat");
    for(double T=5; T<=500; T+=0.005)
    {
        fout << T << "  " << sp_heat(T) << endl;
    }

    return 0;
}