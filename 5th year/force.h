#ifndef FORCE
#define FORCE

#include<matrix.h>


/* 
    Calculating force (dH/d phi = dS/d phi) term = N(phi + phi^3)
*/
double force(complex<double> A[n][n], complex<double> (&dh)[n][n])
{
    double  s, s2, s3, s4;
    complex <double> A2[n][n] , A3[n][n] , A4[n][n];
    //   passing and obtaining phi and phi^3 matrices
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    // calculating force matrix
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            dh[i][j] = (A[i][j] + A3[i][j])*((double)n); 
        }
    }

    return 0;
}

#endif