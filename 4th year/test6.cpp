#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
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
    ofstream fout("test6.dat");
    double N0 = 10000000, lambda=0.08, t0=0,a=0,b=0,x=0,y=0;
    double N=N0, t=t0, h=0.001, dn=0, n[100000], ta[100000], d[100000];
    int i=0, j=0;
    for(i=0; i<=N; i++)
    {
        fout << t << "  " << log(N) << "  "  << log(abs(dn)) << "  " <<  f2(t,N0)<< endl;

       // n[i] = log(N);
       // ta[i] = t;
        //d[i] = log(dn);
        dn = -lambda*N*h;
        N -= lambda*N*h;
        t+=h;
    }

    //a = n[100];
    //b = n[1000];
    //x = ta[100];
    //y = ta[1000];
    //double m = (b-a)/(y-x);
    //cout << "Slope of the graph: " << m << endl;

    return 0;
}