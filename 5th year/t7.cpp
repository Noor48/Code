#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;
const int n=10;

double Box(double& x, double& y)
{
    double p,q;

    p = (double)rand()/(double)RAND_MAX;
    q = (double)rand()/(double)RAND_MAX;

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);
    
    return 0;
}

double matrix(complex<double> A[n][n], complex<double> (&A2)[n][n], complex<double> (&A3)[n][n], complex<double> (&A4)[n][n], double& s, double& s2, double& s3, double& s4)
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
    double p,q,r1,r2, S=0,s, s2, s3, s4;; 

    complex<double> A2[n][n], A3[n][n], A4[n][n];
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    S = n*0.5*(0.5*s2 + 0.25*s4);

    return S;
}

double force(complex<double> A[n][n], complex<double> (&dh)[n][n])
{
    double p,q,r1,r2, s, s2, s3, s4;;

    complex <double> A2[n][n], A3[n][n], A4[n][n];
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
    double p,q,r1,r2,P=0,s, s2, s3, s4;

    complex<double> A2[n][n], A3[n][n], A4[n][n];
    matrix(A,A2,A3,A4,s,s2,s3,s4);

    P = 0.5*s2;

    return P;
}

double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    return action(A) + momentum(B);
}

double molecular(complex<double> (&phi)[n][n], double& hi, double& hf, double nt)
{
    double p, q, r1, r2; 

    complex<double> P[n][n] = {0}, dt=0.01, dh[n][n];

    for(int i=0; i<n-1; i+=1)
    {
        for(int j=i+1; j<n; j+=1)
        {
            Box(p,q);
            P[i][j] = complex(p/sqrt(2),q/sqrt(2));
            P[j][i] = complex(p/sqrt(2),-q/sqrt(2));
        }
    }

    for(int i=0; i<n; i+=1)
    {
        Box(p,q);
        P[i][i] = p;
    }

    hi = hamiltonian(phi,P);

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    force(phi,dh);
    for(int i=1; i<=nt-1; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                P[j][k] -= dh[j][k]*dt;
                phi[j][k] += P[j][k]*dt;
            }
        }
    }

    force(phi,dh);
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            P[i][j] -= dh[i][j]*dt;
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    hf = hamiltonian(phi,P);

    return 0;
}

int main()
{
    srand(time(NULL));
    ofstream fout("t7.dat");
    double hi, hf, s=0, s2=0, r, c=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0};

    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            A[i][j] = 0;
            A0[i][j] = 0;
            
        }
    }
    action(A);
    double C[10000][8] = {0};

    for(double nt=4; nt<=10; nt+=2)
    {
        for(int i=1; i<10000; i+=1)
        {
            for(int j=0; j<n; j+=1)
            {
                for(int k=0; k<n; k+=1)
                {
                    A0[j][k] = A[j][k];
                }
            }
        

            molecular(A,hi,hf,nt);
            r = (double)rand()/(double)RAND_MAX;;
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
            C[i][((int)nt-4)+1] = (double)s/(double)(i*n*n);
        }

        s = 0;

        for(int i=0; i<n; i+=1)
        {
            for(int j=0; j<n; j+=1)
            {
                A[i][j] = 0;
            }
        }
    }

    for(int i=0; i<10000; i+=1)
    {
        for(int j=0; j<8; j+=1)
        {
            fout << C[i][j] << "  ";
        }

        fout << endl;
    }

    return 0;
}