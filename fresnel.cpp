#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact(int n)
{
    if (n<=1)
    {
        return 1;
    }

    else 
    {
        return n*fact(n-1);
    }
}

double f(int n, double z, double theta)
{
    return (pow(z,n))/(pow(2,n+1)*fact(n))*cos(z*cos(theta))*pow(sin(theta),2*n+1);
}

double bessel(int n, double z)
{
    double a=0, b=3.14, I=0, J=0, K=0, A=0, h;
    int N=100;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += f(N, z,a + i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += f(N, z,a + i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += f(N, z,a + i*h);
    }
    
    A = (3*h/8)*(f(N,z,a) + 3*I + 3*J + 2*K + f(N,z,b));

    return A;
}

double ff(double z)
{
    return 0.5*bessel(0,z)*pow(z, 0.5);
}

double fresnel(double x)
{
    double a=0, b=x, I=0, J=0, K=0, A=0, h;
    int N=100;
    h = (b-a)/N;

    for(int i=1; i<N; i+=3)
    {
        I += ff(a + i*h);
    }

    for(int i=2; i<N; i+=3)
    {
        J += ff(a + i*h);
    }
    
    for(int i=3; i<N; i+=3)
    {
        K += ff(a + i*h);
    }
    
    A = (3*h/8)*(ff(a) + 3*I + 3*J + 2*K + ff(b));

    return A;
}
    


int main()
{
    ofstream fout ("bl.dat");
    ofstream file ("fr.dat");
    
    for(double z=0; z<25; z+=0.01)
    {
        fout << z << " " << bessel(0,z) << " " << bessel(1,z) << " " << bessel(2,z) << " " << bessel(3,z) << endl;
    }

    for (double x=0; x<=20; x+=0.1)
    {
        file << x << " " << fresnel(x) << endl;
    }
    return 0;
}