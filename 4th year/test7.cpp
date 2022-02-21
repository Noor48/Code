#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("test7.txt");
    long long N=50000, n=20000, a[N], b[N], x, c[2*n+1];
    double long s, p[2*n+1];
    srand(time(NULL));

    for(long long i=1; i<=N; i+=1)
    {
        x=0;
            //long long r = (rand()%n)+1;  
        
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
