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

double hamil(double x, double p)
{
    double H = S(x) + 0.5*pow(p,2);
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

    hi = hamil(x,p);

    x += 0.5*p*dt;
    
    for(int i=0; i<nt; i++)
    {
        p -= dh(x)*dt;
        x += p*dt;
    }

    p -= dh(x)*dt;
    x += 0.5*p*dt;

    hf = hamil(x,p);

    return 0;
}

int main()
{
    srand(unsigned(time(NULL)));
    ofstream fout("t3.dat");

    double hi, hf, x0, x, n=10E5, r, c, sum2=0;

    x = 0;
    r = (double)rand()/(double)RAND_MAX;

    for(int i=0; i<n; i++)
    {
        x0 = x;

        molecular(x,hi,hf);
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            x = x0;
        }

        sum2 += pow(x,2);

        fout << i << "  "  << sum2/i << "  " << c/i << endl;
    }

    return 0;
}