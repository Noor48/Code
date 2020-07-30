#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1(double m, double theta)
{
    return pow(1-m*pow(sin(theta),2), -0.5);
}

double f2(double m, double theta)
{
    return pow(1-m*pow(sin(theta),2), 0.5);
}

double K(double m)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0,h, n=1000;
    h = (b-a)/n; 

    for (int i=1; i<n; i+=3)
    {
        I += f1(m,a+i*h);
    }

    for (int i=2; i<n; i+=3)
    {
        J += f1(m,a+i*h);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += f1(m,a+i*h);
    }

    A = (3*h/8)*(f1(m,a) + 3*I + 3*J + 2*K + f1(m,b));
    return A;
}

double E(double m)
{
    double a=0, b=M_PI/2, I=0, J=0, K=0, A=0,h, n=1000;
    h = (b-a)/n; 

    for (int i=1; i<n; i+=3)
    {
        I += f2(m,a+i*h);
    }

    for (int i=2; i<n; i+=3)
    {
        J += f2(m,a+i*h);
    }
    
    for (int i=3; i<n; i+=3)
    {
        K += f2(m,a+i*h);
    }

    A = (3*h/8)*(f2(m,a) + 3*I + 3*J + 2*K + f2(m,b));
    return A;
}

double penduT(double thetaM)
{
    return 4*pow(0.0253,0.5)*K(pow(sin(thetaM/2),2));
}

int main()
{
    ofstream fout ("elip.dat");
    ofstream file("per.dat");
    for(double m=-1; m<=1; m+=0.01)
    {
        fout << m << " " << K(m) << " " << E(m) << endl;
    }

    for(double thetaM=0; thetaM<=M_PI; thetaM+=M_PI/30)
    {
        file << thetaM << " " << penduT(thetaM) << endl;
    }

    return 0;
}
