#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double t, double N)
{
    return 0.1*exp(-0.1*t)-0.08*N;
}

void pop(double t0, double N0)
{
    ofstream fout ("pop.dat");
    double N=N0, k1,k2,k3,k4,s=0, h=0.0001;

    for(double t=t0; t<=100; t+=0.001)
    {
        fout << t << "  " << N << endl;

        k1 = h*f1(t,N);
        k2 = h*f1(t+h/2,N+k1/2);
        k2 = h*f1(t+h/2,N+k2/2);
        k4 = h*f1(t+h,N+k4);
        
        N += (k1 + 2*k2 + 2*k3 + k4)/6;
    }
}

int main()
{
    pop(0,0);

    return 0;
}