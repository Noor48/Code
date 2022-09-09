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
    q = sqrt(-2*log(r))*sin(2*M_PI*s);
    
    return 0;
}

int main()
{
    double r1,r2,x,p,q; 
    complex <double> A[5][5] = {0};
    complex <double> A2[5][5] = {0};
    complex <double> A3[5][5] = {0};
    complex <double> A4[5][5] = {0};

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

    return 0;
}

