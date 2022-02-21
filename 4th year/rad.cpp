#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double r1(double t, double N)
{
    return N*exp(-0.08*t);
}

int main()
{
    ofstream fout("rad.dat");
    double N0, dN, dt=0.001, lambda, t=0, n[1001], ti[1001], dn[1001];
    cout << "Enter inital particle number: " << endl;
    cin >> N0;
    cout << "Enter decay constant: " << endl;
    cin >> lambda;
    double N=N0;
    for(int i=0; i<=1000; i++)
    {
        fout << t << "  " << log(N) << " " << log(abs(dN)) << endl;
        ti[i] = t;
        n[i] = log(N);
        dn[i] = log(abs(dN));
        dN = -lambda*N*dt;
        //N = N + dN;
       N -= lambda*N*dt;
       t+=dt;
        //N -= 0.08*Ndt;
    }
    double a, b, c, d;
    a = n[100];
    b = n[1000];
    c = ti[100];
    d = ti[1000];
    double m = (b-a)/(d-c);
    cout << "Slope of the grpah: " << m << endl;

    return 0;
}