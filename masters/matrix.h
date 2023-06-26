#ifndef MATRIX
#define MATRIX


#include<complex>
using namespace std;

//matrix dimension
const int n=10;


/* 
    Declaring a function for easily calling a matrix, it 2nd, 3rd, 4th order terms, and their traces.
*/
double matrix(complex<double> A[n][n], complex<double> (&A2)[n][n], complex<double> (&A3)[n][n], complex<double> (&A4)[n][n], double& s, double& s2, double& s3, double& s4)
{
    s=0, s2=0, s3=0, s4=0;

    // 2nd Order matrix
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

    //  3rd order matrix
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
    
    // 4th order matrix
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

    //  Trace of A
    for(int i=0; i<n; i+=1)
    {
        s += A[i][i].real();
    }

    // Trace of A^2
    for(int i=0; i<n; i+=1)
    {
        s2 += A2[i][i].real();
    }
    
    //  Trace of A^3
    for(int i=0; i<n; i+=1)
    {
        s3 += A3[i][i].real();
    }
    
    //  Trace of A^4
    for(int i=0; i<n; i+=1)
    {
        s4 += A4[i][i].real();
    }
    
    return 0;
}

#endif