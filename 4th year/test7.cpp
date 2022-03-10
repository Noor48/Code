/*
A box is divided into two side with a barrier. There is N number of particles are held in the left side of the barrier of the box at beginning.
Let a small hole is created in the the barrier and one particle can pass though the hole per unit time.

1:-  Write down a code and draw a graph to determint the time for the particles to be in equilibrium position, 
     hince both left and right side have N/2 number of particle.

2:-  Solve dnl/dt= 1-(2*nl/N); and plot the graph. Compair your result with problem 1.
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("test7.dat");
    long long N=5000, n=2000, a[N], b[N], x, c[2*n+1];
    double long s, p[2*n+1];
    srand(time(NULL));

    for(long long i=1; i<=N; i+=1)
    {
        x=0;
            long long r = (rand()%n)+1;  
        
        for(long long j=1; j<=n; j+=1)
        {
            s = (double)rand()/(double)RAND_MAX;
            if(s>0.5)
            {
                x+=1;
            }
            else
            {
                x-=1;
            }
        }
        a[i]=x;
        //cout << a[i] << endl;
    }

    for(long long i=-n; i<=n; i++)
    {
        for(long long j=1; j<=N; j++)
        {
            if(i == a[j])
            {
                c[i+n]++;
            }
            //cout << c[i+n] << endl;
        }
    }

    for(long long i=1; i<=2*n+1; i++)
    {
        p[i] = (double)c[i]/(double)N;
        if(p[i]!=0)
        {
            fout << i-n << "  " << p[i] << endl; 
        }
    }
    return 0;
}
