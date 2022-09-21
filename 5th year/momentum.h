#ifndef MOM
#define MOM
#include<complex>
#include<matrix.h>


/* 
    Calculating kinetic part (1/2)Tr P^2
*/
double momentum(complex<double> A[n][n])
{
    double P=0,s, s2, s3, s4;
    complex<double> A2[n][n] , A3[n][n] , A4[n][n] ;
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    P = 0.5*s2;

    return P;
}

#endif