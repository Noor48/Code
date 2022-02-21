#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("r3.dat");
    int N=100000, n=100, x,y;
    int a[N], m[2*n+1]; 
    double s, na[2*n+1];
    srand(time(NULL));

    for(int i=0; i<=N; i++)
    {
        x=0;
        int r = (rand()%n)+1;
        for(int j=0; j<=r; j++)
        {
            s = (double)rand()/(double)RAND_MAX;
            if(s>0.5)
            {
                x++;
            }

            else
            {
                x--;
            }
        }
        a[i] = x;
    }

    for(int i=-n; i<=n; i++)
    {
        y=0;
        for(int j=0; j<=N; j++)
        {
            if(i==a[j])
            {
                y++;
            }
        }
        m[i+n] = y;
    }

    for(int i=0; i<=2*n+1; i++)
    {
        na[i] = (double)m[i]/(double)N;
        if(m[i] != 0 )
        {
            fout << i-n << "  " << na[i] << endl;
        }
    }

    return 0;   
}