#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<complex>
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

double phi(double x)
{
    complex <double> A[5][5] ={0};
    complex <double> A2[5][5] = {0};
    complex <double> A3[5][5] = {0};
    complex <double> A4[5][5] = {0};
    
    double r1,r2,p,q;
    Box(r1.r2);
    for(int i=0; i<5-1; i+=1)
    {
        for(int j=i+1; j<5; j+=1)
        {
            p = (double)rand()/(double)RAND_MAX;
            q = (double)rand()/(double)RAND_MAX;
            A[i][j] = ;
        }
    }
    
    for(int i=0; i<5; i+=1)
    {
        for(int j=0; j<5; j+=1)
        {
            A2[i][j] = A[i][k]*A[k][j];
        }
    }

    for(int i=0; i<5; i+=1)
    {
        for(int j=0; j<5; j+=1)
        {
            A3[i][j] = A2[i][k]*A[k][j];
        }
    }
    
    for(int i=0; i<5; i+=1)
    {
        for(int j=0; j<5; j+=1)
        {
            A4[i][j] = A3[i][k]*A[k][j];
        }
    }
    
    return 0;
}

double S(double x)
{
    return 0.5*pow(x,2);
}

double H(double x, double p)
{
    return 0.5*pow(p,2) + S(x);
}

double dh(double x)
{
    return x;
}

double Molecular(double& x, double& hi, double& hf)
{
    double p, r1, r2, nt=40, dt=1;
    Box(r1,r2);

    p = r1;

    hi = H(x,p);
    
    x += 0.5*p*dt;

    for(int i=1; i<nt; i+=1)
    {
        p -= dh(x)*dt;
        x += p*dt;
    }

    p -= dh(x)*dt;
    x += 0.5*p*dt;

    hf = H(x,p);

    return 0;
}

int main()
{
    srand(time(NULL));

    ofstream fout("t6.dat");

    double x0, x, hi, hf,c=0, r, n=10E5, sum=0, sum2=0;

    x=0;

    for(int i=0; i<=n; i+=1)
    {
        x0 = x;
        Molecular(x, hi, hf);
        r = (double)rand()/(double)RAND_MAX;
        
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            x = x0;
        }

        sum += x;
        sum2 += pow(x,2);

        fout << i << "  " << sum/i << "  " << sum2/i << "  " << c/i << endl;
    }

    return 0;
}