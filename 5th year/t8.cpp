#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;
const int n=10;         // square matrix size


//  To generate random number between [0,1]
double ran()
{   
    return (double)rand()/(double)RAND_MAX; 
}


/* 
    To generate random number using Box-Muller method

*/
double Box(double& x, double& y)
{
    double p,q;

    p = ran();
    q = ran();

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);
    
    return 0;
}
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

/* 
    Calculating Hamiltonian
*/
double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    return action(A) + momentum(B);
}

/*
    Molecular dynamics part
*/
double molecular(complex<double> (&phi)[n][n], double& hi, double& hf, double nt)
{
    double p, q, r1, r2; 

    complex<double> P[n][n] = {0}, dt=0.01, dh[n][n] = {};

    //  Generating hermitian auxiliary momentum matrix 
    for(int i=0; i<n-1; i+=1)
    {
        for(int j=i+1; j<n; j+=1)
        {
            Box(r1,r2);
            p=r1;
            q=r2;
            P[i][j] = complex(p/sqrt(2),q/sqrt(2));
            P[j][i] = complex(p/sqrt(2),-q/sqrt(2));
        }
    }

    for(int i=0; i<n; i+=1)
    {
        Box(p,q);
        P[i][i] = p;
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
    
    //calling force term
    //late step of leap frog method
    //pi(nt *dt) = pi((nt-1)dt) -  (ds/dx)((nt-1/2)dt)dt
    //xi(nt* dt) = xi((nt-1)dt) + p(nt *dt) dt/2;
    force(phi,dh);
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

int main()
{
    srand(time(NULL));
    ofstream fout("t8.dat");
    double hi, hf, s=0, s2=0, r, c=0;
    //x=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0};
    
    //caling action for x=0
    action(A);
    //for storing data in an array
    double C[10000][8] = {0};

    //for multiple nt value
    for(double nt=4; nt<=10; nt+=2)
    {
        //metropolis test
        for(int i=1; i<10000; i+=1)
        {
            for(int j=0; j<n; j+=1)
            {
                for(int k=0; k<n; k+=1)
                {   
                    //x0=x
                    A0[j][k] = A[j][k];
                }
            }
            
            molecular(A,hi,hf,nt);
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

            s += action(A);
            C[i][((int)nt-4)] = nt*i;
            C[i][((int)nt-4)+1] = (double)s/(double)i/(double)(n*n);
        }

        s = 0;

        A[n][n] = {};
        
    }

    //calling stored value of previus array
    for(int i=1; i<10000; i+=1)
    {
        for(int j=0; j<8; j+=1)
        {
            fout << C[i][j] << "  ";
        }
        fout << endl;
    }

    return 0;
}