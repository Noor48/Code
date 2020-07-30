#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double t)
{
    double g=9.8, m=0.25, k=0.1, h0=300;

    return h0-(m*k/g)*t+(pow(m,2)*g/pow(k,2))*(1-exp(k*t/m));
}

int main()
{
    ofstream fout ("fall.dat");

    for(double t=0; t<=20; t+=0.001)
    {
        fout << t << "  " << f(t) << endl;
    }

    return 0;
}