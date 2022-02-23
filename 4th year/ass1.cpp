/*
Consider on walking in a 1-dimentional linear path. The walkers are starting from the 0 point and moving forward or backward by generating
random numbers between 0 to 1. If the number is greater then 0.5 the person move right or else in left. Find the probability of landing at 
a given spot after a given number of step with a given walk and also draw the position vs probability graph.
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("ass1.dat");
    long long N=100000, n=10000, a[N], x, y, c[2*n+1];
    double long s, p[2*n+1];
    srand(time(NULL));

    for(long long i=1; i<=N; i+=1)
    {
        x=0;
            long long r = (rand()%n)+1;  
        
        for(long long j=0; j<=r; j+=1)
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
    }

    for(long long i=-n; i<=n; i++)
    {   
        y=0;
        for(long long j=1; j<=N; j++)
        {
            if(i == a[j])
            {
                y+=1;
            }
        }
        c[i+n]=y;
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