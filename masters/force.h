#ifndef FORCE
#define FORCE

#include<~/matrix.h>


/* 
    Calculating force (dH/d phi = dS/d phi) term = p
*/
double force(complex<double> A[n][n], complex<double> (&dh)[n][n])
{
    // calculating force matrix
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            dh[i][j] = (A[i][j]); 
        }
    }

    return 0;
}

#endif
