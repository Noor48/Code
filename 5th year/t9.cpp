#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;
const int n=10;

double ran()
{
    return (double)rand()/(double)RAND_MAX;
}

double Box(double& x, double& y)
{
    double p,q;

    p = ran();
    q = ran();

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);
    
    return 0;
}

double matrix(complex<double> A[n][n], complex<double> (&A2)[n][n], complex<double> (&A3)[n][n], complex<double> (&A4)[n][n], double& s, double& s2, double& s3, double& s4)
{
    s=0, s2=0, s3=0, s4=0;

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                A2[i][j] += A[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                A3[i][j] += A2[i][k]*A[k][j];
            }
        }
    }
    
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                A4[i][j] += A3[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<n; i+=1)
    {
        s += A[i][i].real();
    }

    
    for(int i=0; i<n; i+=1)
    {
        s2 += A2[i][i].real();
    }
    
    for(int i=0; i<n; i+=1)
    {
        s3 += A3[i][i].real();
    }
    
    for(int i=0; i<n; i+=1)
    {
        s4 += A4[i][i].real();
    }
    
    return 0;
}

double force(complex<double> A[n][n], complex<double> (&dh)[n][n])
{
    double p,q,r1,r2, s, s2, s3, s4;

    complex <double> A2[n][n] , A3[n][n] , A4[n][n] ;
    //matrix(A,A2,A3,A4,s,s2,s3,s4);

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            dh[i][j] = (A[i][j])*((double)n); 
        }
    }

    return 0;
}

double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    complex <double> H[n][n] = {0}, N1[n][n] = {0}, N2[n][n] = {0};
    double sum=0;

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                N1[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                N2[i][j] += B[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            H[i][j] = N1[i][j] + N2[i][j];
        }
    }

    for(int i=0; i<n; i+=1)
    {
        sum += H[i][i].real();
    }

    return sum;
}

double molecular(complex<double> (&phi)[n][n],complex<double> (&P)[n][n], double& hi, double& hf, double nt)
{
    double p, q, r1, r2; 

    complex<double> dt=0.01, dh[n][n] = {};

    hi = hamiltonian(phi,P);

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    
    for(int i=1; i<=nt-1; i+=1)
    {
        force(phi,dh);
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                P[j][k] -= dh[j][k]*dt;
                phi[j][k] += P[j][k]*dt;
            }
        }
    }

    force(phi,dh);
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            P[i][j] -= dh[i][j]*dt;
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    hf = hamiltonian(phi,P);

    return 0;
}

int main()
{
    srand(time(NULL));
    ofstream fout("t9.dat");
    double hi, hf, s=0, s2=0, r, c=0,p,q;
    complex<double> A[n][n] = {0}, A0[n][n] = {0}, B[n][n] = {0};
    double C[10000][8] = {0};

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            Box(p,q);
            A[i][j] = complex(p/sqrt(2),q/sqrt(2));
        }
    }

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            Box(p,q);
            B[i][j] = complex(p/sqrt(2),q/sqrt(2));
        }
    }
    
    for(int i=1; i<10000; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                A0[j][k] = A[j][k];
            }
        }

        molecular(A,B,hi,hf,10);
        r = ran();
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            for(int j=0; j<n; j+=1)
            {
                for(int k=0; k<n; k+=1)
                {
                    A[j][k] = A0[j][k];
                }
            }
        }

        s += hamiltonian(A,B);

        fout << i << "  " << (double)s/(double)(i*n*n) << endl;
        
    }
    return 0;
}