#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double t, double N)
{
    return -0.08*N;
}
double f2(double t, double N)
{
    return N*exp(-0.08*t);
}

int main()
{
    ofstream fout("test5.txt");
    double N0=1*pow(10,8), t0=0;
    double N=N0, t=t0, k1, k2, k3, k4, h=0.0001, dn=0;
    for(t=t0; t<=100; t+=h)
    {
        fout << t << "  " << log(N) << "  "  << log(abs(dn)) << "  " <<  f2(t,N0)<< endl;

       dn = -0.08*N*h;
       // N += dn;
       N -= 0.08*N*h;
    }

    return 0;
}