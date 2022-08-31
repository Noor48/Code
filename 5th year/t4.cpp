#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<complex>
using namespace std;

int main()
{
    srand(time(NULL));
    complex <double> A[5][5] = {0};
    complex <double> B[5][5] = {0};
    
    double p,q;

    //Generating hermitian matrix
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<5; j++)
        {   
            p = (double)rand()/(double)RAND_MAX;
            q = (double)rand()/(double)RAND_MAX;
            A[i][j] = complex(p,q);
            A[j][i] = complex(p,-q);
        }
    }

    // Diagonal component
    for(int i=0; i<5; i++)
    {
        p = (double)rand()/(double)RAND_MAX;
        q = (double)rand()/(double)RAND_MAX;
        A[i][i] = p;
    }

    // Output of the matrix
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(j==i)
            {
                cout << noshowpos <<A[i][i].real() << " ";
            }
            
            else
            {
                cout <<noshowpos << A[i][j].real() << showpos << A[i][j].imag() << "i" << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}