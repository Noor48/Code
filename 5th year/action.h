#ifndef ACTION
#define ACTION
#include<matrix.h>

/* 
    Calculating Action S = N*Tr(0.5*phi^2 + 0.25*phi^4)
*/
double action(complex<double> A[n][n]) //   for passing the value of phi[n][n]
{
    // Initializing some parameter for referencing in matrix function 
    double S=0,s, s2, s3, s4;
    complex<double> A2[n][n] , A3[n][n] , A4[n][n];

    // calling the matrix function
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    // S = N*Tr(0.5*phi^2 + 0.25*phi^4)
    S = n*(0.5*s2 + 0.25*s4);

    return S;
}

#endif