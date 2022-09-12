#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;

double Box(double& p, double& q)
{
    double r,s;

    r = (double)rand()/(double)RAND_MAX;
    s = (double)rand()/(double)RAND_MAX;
    
    p = sqrt(-2*log(r))*sin(2*M_PI*s);
    q = sqrt(-2*log(r))*cos(2*M_PI*s);
    
    return 0;
}

double phi(complex <double> A[10][10])
{
    double r1,r2,x,p,q,sum=0,sum2=0, S; 
    //complex <double> A[5][5] = {0};
    complex <double> A2[10][10] = {0};
    complex <double> A3[10][10] = {0};
    complex <double> A4[10][10] = {0};
    /*
    for(int i=0; i<5-1; i+=1)
    {
        for(int j=i+1; j<5; j+=1)
        {   
            Box(r1,r2);
            p=r1;
            q=r2;
            A[i][j] = complex(p/sqrt(2),q/sqrt(2));
            A[j][i] = complex(p/sqrt(2),-q/sqrt(2));
        }
    }

    for(int i=0; i<5; i+=1)
    {
        Box(r1,r2);
        p=r1;
        A[i][i] = p;
    }
    */
    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                A2[i][j] += A[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                A3[i][j] += A2[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                A4[i][j] += A3[i][k]*A[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        sum += A2[i][i].real();
    }
    
    for(int i=0; i<10; i+=1)
    {
        sum2 += A4[i][i].real();
    }
    
    S = 5*(0.5*sum + 0.25*sum2);
    //S = 0.5*sum;

/*
    cout << S << endl;

    for(int i=0; i<5; i+=1)
    {
        for(int j=0; j<5; j+=1)
        {
            if(j==i)
            {
                cout << noshowpos << A[i][i].real() << "  ";
            }

            else
            {
                cout << noshowpos << A[i][j].real() << showpos << A[i][j].imag() << "i" << "  ";
            }
        }
        cout << endl;
    }
*/
    return S;
}

double delh(complex <double> (&dh)[10][10], complex <double> phi[10][10])
{
    double r1,r2,p,q,sum=0, sum2=0;

    complex <double> phi2[10][10] = {0}, phi3[10][10] = {0};


    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                phi2[i][j] += phi[i][k]*phi[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                phi3[i][j] += phi2[i][k]*phi[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            dh[i][j] = (phi[i][j] + phi3[i][j])*((double)5);
            //dh[i][j] = phi[i][j]; 
        }
    }

    return 0;
}

double P_phi(complex <double> B[10][10])
{
    double r1,r2,p,q,sum=0, sum2=0, P;

    complex <double> B2[10][10] = {0};

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                B2[i][j] += B[i][k]*B[k][j];
            }
        }
    }

    for(int i=0; i<10; i+=1)
    {
        sum += B2[i][i].real();
    }

    P = 0.5*sum; 

    return P;
}

double H(complex <double> A[10][10], complex <double> B[10][10])
{
    return phi(A) + P_phi(B);
} 

double molecular(complex <double> (&phi)[10][10],double& hi, double& hf)
{
    double r1,r2,p,q,nt=10, sum=0;
    complex <double> P[10][10] = {0}, dt=0.01, dh[10][10];

    for(int i=0; i<10-1; i+=1)
    {
        for(int j=i+1; j<10; j+=1)
        {   
            Box(r1,r2);
            p=r1;
            q=r2;
            P[i][j] = complex(p/sqrt(2),q/sqrt(2));
            P[j][i] = complex(p/sqrt(2),-q/sqrt(2));
        }
    }

    for(int i=0; i<10; i+=1)
    {
        Box(r1,r2);
        p = r1;
        P[i][i] = p;
    }

    hi = H(phi,P);

    for(int i=0; i<10; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            phi[i][j] += 0.5*P[i][j]*dt;
        }
    }

    
    for(int i=1; i<=nt; i+=1)
    { 
        delh(dh,phi);
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                P[j][k] -= dh[j][k]*dt;
                phi[j][k] += P[j][k]*dt;
            }
        }

    }

    delh(dh,phi);
    for(int j=0; j<10; j+=1)
    {
        for(int k=0; k<10; k+=1)
        {
            P[j][k] -= dh[j][k]*dt;
            phi[j][k] += 0.5*P[j][k]*dt;
        }
    }

    hf = H(phi,P);

    return 0;
}
int main()
{
    srand(time(NULL));
    ofstream fout("t6.dat");
    double hi,hf,sum=0,sum2=0, r,c=0;
    complex <double> A[10][10] = {0}, A0[10][10] = {0};
    phi(A);
 
    for(int i=0; i<10E4; i+=1)
    {
        for(int j=0; j<10; j+=1)
        {
            for(int k=0; k<10; k+=1)
            {
                A0[j][k] = A[j][k];
            }
        }

        molecular(A,hi,hf);
        r=(double)rand()/(double)RAND_MAX;
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            for(int j=0; j<10; j+=1)
            {
                for(int k=0; k<10; k+=1)
                {
                    A[j][k] = A0[j][k];
                }
            }
        }

        sum += phi(A);

        fout << i << "  " << (double)sum/(double)i/(double)100 << "  " << endl; 
    }

    return 0;
}