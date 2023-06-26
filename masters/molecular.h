#ifndef MOL
#define MOL

#include<~/box.h>
#include<~/force.h>
#include<~/hamiltonian.h>



/*
    Molecular dynamics part
*/
double molecular(complex<double> (&phi)[n][n], complex<double> (&P)[n][n], double& hi, double& hf)
{
    
    double p, q, r1, r2,nt=10; 

    complex<double>  dt=0.001, dh[n][n] = {0};

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            Box(p,q);
            P[i][j] = complex(p/sqrt(2),q/sqrt(2));
        }
    }

    // Initial hamiltonian of molecular dynamics
    hi = hamiltonian(phi,P);


    //leap frog method 
    // xi(dt/2) = xi(0) + pi(0)dt/2;
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    // for n=1 to nt steps
    //pi(ndt) = pi((n-1)dt) - (ds/dx)((n-1/2)dt)dt
    for(int i=1; i<=nt-1; i+=1)
    {
        //calling force term
        force(P,dh);
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                P[j][k] -= dh[j][k]*dt;
                phi[j][k] += P[j][k]*dt;
            }
        }
    }
    
    //calling force term
    //late step of leap frog method
    //pi(nt *dt) = pi((nt-1)dt) -  (ds/dx)((nt-1/2)dt)dt
    //xi(nt* dt) = xi((nt-1)dt) + p(nt *dt) dt/2;
    force(P,dh);
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            P[i][j] -= dh[i][j]*dt;
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    //final hamiltonian of molecular dynamics
    hf = hamiltonian(phi,P);

    return 0;
}

#endif
