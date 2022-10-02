#include<iostream>
#include<cmath>
#include<fstream>
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

double S(double x)
{
    return 0.5*pow(x,2);
}

double ham(double x, double p)
{
    double H = 0.5*pow(p,2) + 0.5*pow(x,2);
    return H;
}

double dh(double x)
{
    return x;
}

double molecular(double& x, double& hi, double& hf)
{
    double p, r1, r2, nt=10,dt=1;
    Box(r1,r2);
    p = r1;

    hi = ham(x,p);

    x += 0.5*p*dt;
    
    for(int i=0; i<nt; i++)
    {
        p -= dh(x)*dt;
        x += p*dt;
    }

    p -= dh(x)*dt;
    x += 0.5*p*dt;

    hf = ham(x,p);

    return 0;
}

int main()
{
    srand(unsigned(time(NULL)));
    ofstream fout("t3.dat");
    ofstream file("t3p.dat");

    double hi, hf, x0, x, n=10000, r, c, sum=0,sum2=0, p,z=0;

    x = 0;
    

    for(int i=0; i<n; i++)
    {
        x0 = x;

        r = (double)rand()/(double)RAND_MAX;
        
        molecular(x,hi,hf);
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            x = x0;
        }
        sum = x;
        sum2 += pow(x,2);

        p = hf;
        z += exp(-i*p/(298*1.38E-23));
        file << i << "  " << z << endl;
        fout << i << "  "  << sum/i << "  "<<  sum2/i << "  " << c/i << endl;
    }

    return 0;
}