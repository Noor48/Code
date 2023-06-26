#ifndef HAM
#define HAM



/* 
    Calculating Hamiltonian of Berry-Keating H = (1/2)(xp+px)
*/
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


    return 0.5*sum;
}


#endif
