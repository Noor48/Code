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

double matrix(complex<double> A[n][n], complex<double> (&A2)[n][n], complex<double> (&A3)[n][n], complex<double> (&A4)[n][n], double s, double s2, double s3, double s4)
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

double action(complex<double> A[n][n])
{
    double p,q,r1,r2, S=0; 

    complex<double> A2[n][n], A3[n][n], A4[n][n], s, s2, s3, s4;
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    S = n*0.5*(0.5*s2 + 0.25*s4);

    return S;
}

double force(complex<double> A[n][n], complex<double> (&dh)[n][n])
{
    double p,q,r1,r2;

    complex <double> A2[n][n], A3[n][n], A4[n][n], s, s2, s3, s4;
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            dh[i][j] = A[i][j] + A3[i][j]; 
        }
    }

    return 0;
}

double momentum(complex<double> A[n][n])
{
    double p,q,r1,r2,P=0;

    complex<double> A2[n][n], A3[n][n], A4[n][n], s, s2, s3, s4;
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    P = n*0.5*s2;

    return P;
}

double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    return action(A) + momentum(B);
}

double molecular(complex<double> (&A)[n][n], double& hi, double& hf, double& nt)
{
    double p, q, r1, r2; 
}