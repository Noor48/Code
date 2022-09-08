#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<complex>
using namespace std;

tuple <complex <double>> phi;
double Box(double& x, double& y)
{
    double p, q;

    p = (double)rand()/(double)RAND_MAX;
    q = (double)rand()/(double)RAND_MAX;

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);

    return 0;
}

double S(double x)
{
    return 0.5*pow(x,2);
}
double H(double x, double p)
{
    return 0.5*pow(p,2) + S(x);
}

double dh(double x)
{
    return x;
}
double molecular(double& x, double& hi, double& hf)
{
    double p, r1,r2,nt=40,dt=1;
    Box(r1,r2);
    p=r1;

    hi = H(x,p);

    x += 0.5*p*dt;

    for(int i=0; i<nt; i+=1)
    {
        p -= dh(x)*dt;
        x += p*dt;
    }

    p -= dh(x)*dt;
    x += 0.5*p*dt;

    return 0;
}