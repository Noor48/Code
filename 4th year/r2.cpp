#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("r2.dat");
    long N=1000000, n=10000, a[N],x , c[2*n+1], y;
    double s, p[2*n+1];
    srand(time(NULL));

    for(long i=0; i<=N; i+=1)
    {
        x=0;
        long r = (rand()%n)+1;
        for(long j=0; j<=r; j+=1)
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

    for(long i=-n; i<=n; i+=1)
    {   
        y=0;
        for(long j=0; j<=N; j+=1)
        {
            if(i == a[j])
            {
                y++;
            }
        }
        c[i+n] = y;
    }

    for(long i=0; i<=2*n+1; i++)
    {
        p[i] = (double)c[i]/(double)N;
        if(c[i] != 0)
        {
            fout << i-n << "  " << p[i] << endl;
        }
    }

    return 0;
}