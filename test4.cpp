#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double S, double T)
{
    double N=1*pow(10,3), V = 100, m=9.1*pow(10, -31), k=1.38*pow(10, -23), h=6.634*pow(10,-34); 
    return log((V/N)*(pow((2*M_PI*m*k*T)/pow(h,2),(3/2)))) + (5/2);
}

void r(double S0, double T0)
{
    ofstream fout("test4.dat");
    double S=S0, T=T0, h=0.001, N=1*pow(10,3);
    for(T=T0; T<=100; T+=h)
    {
        fout << T << "  " << f1(S,T)/(N*1.38*pow(10, -23)) << endl;
    }
}

int main()
{
    r(0,0);
    return 0;
}