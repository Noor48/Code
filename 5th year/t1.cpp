#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

double Box(double& x, double& y)
{
    double p,q;
    p = (double)rand()/(double)RAND_MAX;
    q = (double)rand()/(double)RAND_MAX;
    
    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);

    return 0;
}

double action(double x)
{
    return pow(x,2)*0.5;
}

double hamil(double x, double p)
{
    return action(x) + 0.5*pow(p,2);
}

double dh(double x)
{
    return x;
}

double molecular(double& x, double& h0, double& hf)
{
    double N=40, dt = 1;
    double r1,r2,p;
    Box(r1,r2);
    p=r1;

    h0=hamil(x,p);

    x += p*dt;

    for(int i=1; i<=N; i++)
    {   

        p += -dh(x)*dt;
        x += p*dt;
    }


    p += -dh(x)*dt;
    x += p*dt*0.5;

    hf = action(x) + 0.5*pow(p,2);

    return 0;
}

int main()
{
    srand(time(NULL));

    ofstream fout("t1.dat");
    double n=1000, sum=0, x=0, r, x0, h0, hf;
    int k, i=0;

    r = (double)rand()/(double)RAND_MAX;
    
    for(k=1; k<=n; k++)
    {
        x0 = x;
        molecular(x, h0, hf);

        if(exp(h0-hf)>r)
        {
            i+=1;
        }

        else
        {
            x = x0;
        }

        sum += pow(x,2);

        fout << x << "  " << sum/k << "  " << i/k  << "  " << k << endl; 
    }

    return 0;
}