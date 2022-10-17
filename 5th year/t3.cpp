#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;

double Box(double& x, double& y)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> o1(0, 1); 
    double p,q;
    p = o1(mt);
    q = o1(mt);

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
    double H = 0.5*(x*p+p*x);
    return H;
}

double dh(double p)
{
    return p;
}

double molecular(double& x, double& hi, double& hf, double& p)
{
    double r1, r2, nt=10,dt=0.001;
    Box(r1,r2);
    p = r1;

    hi = ham(x,p);

    x += 0.5*p*dt;
    
    for(int i=1; i<nt; i++)
    {
        p -= dh(p)*dt;
        x += p*dt;
    }

    p -= dh(p)*dt;
    x += 0.5*p*dt;

    hf = ham(x,p);

    return 0;
}

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> o1(0, 1); 
    srand(unsigned(time(NULL)));
    ofstream fout("t3.dat");
    ofstream file("t3p.dat");

    double hi, hf, x0, x, n=10000, r, c, sum=0,sum2=0, p,z=0,f, r1,r2;

    Box(r1,r2);

    x = o1(mt);
    //p=r2;
    

    for(int i=1; i<n; i++)
    {
        x0 = x;

        r = o1(mt);
        
        molecular(x,hi,hf,p);
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            x = x0;
        }

        cout << x << "  " << p << endl;
        sum = ham(x,p);
        sum2 += sum;
        fout << i << "  "  << (double)sum/(double)i << "  "<<  (double)sum2/(double)i << "  " << c/i << endl;
    }

    return 0;
}