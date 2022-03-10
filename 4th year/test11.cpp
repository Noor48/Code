#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    ofstream fout("a1q2.dat");
    long long N=100000,n=10000,x,y,c[2n+1],a[N];
    double long s,p[2n+1];
    srand(time(NULL));
    
    for(int i=1;i<=N;i++)
    {
        x=0;
        for(int j=1;j<=n;j++)
        {
            s=(double)rand()/(double)RAND_MAX;
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
    
    for(int i=-n;i<=n;i++)
    {
        y=0;
        for(int j=1;j<=N;j++)
        {
        if(i==a[j])
        {
            y+=1;
        }
        }
        c[i+n]=y;
        }
        for(int i=1;i<=2*n+1;i++)
        {
            p[i]=(double)c[i]/(double)N;
            if(p[i]!=0)
            {
                fout<<i-n<<" "<<p[i]<<endl;
            }
    }
    return 0;
}