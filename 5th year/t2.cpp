#include<iostream>
#include<cstdlib>
#include<cmath>
#include<complex>
using namespace std;

int main()
{
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3]={0};
    double r,m;

    int a=0;
    complex<double> C[2][2] = {{{1,0},{1,-1}},{{1,1},{1,0}}};
    complex<double> D[2][2] = {0};
    complex<double> E[2][2] = {0};
    complex<double> F[2][2] = {0};

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            B[j][i] = A[i][j];
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
          //  cout << B[i][j] << "  ";
        }

        //cout << endl;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout << C[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            D[j][i] = C[i][j];
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            E[i][j] = conj(D[i][j]);
            if(imag(E[i][j])==-0)
            {
                r = real(E[i][j]);
                m = abs(imag(E[i][j]));
                E[i][j] = {r,m};
                
            }
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout << E[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(E[i][j]== C[i][j])
            {
                a += 1;
            }
        }
    }

    if(a==4)
    {
        cout << "Hermitian" << endl;
    }

    return 0;
}