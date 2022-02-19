#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("test7.txt");
    int N=100000, n=100, a[N], b[N], x, c[2*n+1];
    double s, p[2*n+1];
    srand(time(NULL));

    for(int i=0; i<=N; i+=1)
    {
        x=0;
            int r = (rand()%n)+1;  
        
        for(int j=0; j<=r; j+=1)
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
        cout << a[i] << endl;
    }

    for(int i=-n; i<=n; i++)
    {
        for(int j=0; j<=N; j++)
        {
            if(i == a[j])
            {
                c[i+n]++;
            }
        }
    }

    for(int i=0; i<=2*n+1; i++)
    {
        p[i] = (double)c[i]/(double)N;
        //if(p[i]!=0)
        {
            fout << i-n << "  " << p[i] << endl; 
        }
    }

    return 0;    
}
