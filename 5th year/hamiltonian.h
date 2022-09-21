#ifndef HAM
#define HAM

#include<momentum.h>
#include<action.h>


/* 
    Calculating Hamiltonian
*/
double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    return action(A) + momentum(B);
}

#endif