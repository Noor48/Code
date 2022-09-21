#include<momentum.h>
#include<action.h>
#include<box.h>
#include<force.h>
#include<molecular.h>
#include<matrix.h>
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream fout("main.dat");
    double hi, hf, s=0, s2=0, r, c=0;
    const int n=10;
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
            r = (double)rand()/(double)RAND_MAX;
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