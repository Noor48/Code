#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;
double r1(int N, int n)
{
    ofstream fout("rand.dat");
    srand(time(NULL));
    int a[N], x;
    for(int i=0; i<N; i++)
    {   
        x=0;
        for(int i=0; i<n; i++)
        {
            double s = (double)rand()/(double)RAND_MAX;
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
    
/*    int y, z;
    for(int x=0; x<N-1; x++)
    {
        int y = x;
        for(z=x+1; z<N; z++)
        {
            if(a[z] < a[y])
            {
                y = z;
            }
        }

        swap(a[x], a[y]);
    }

    for(int i=0; i<N; i++)
    {
        cout << a[i] << endl;
    } */
int b[N];
for(long i=-1000; i<1000; i++)
{
    int y=0;
    for(int j=0; j<N; j++)
    {
        if(i == a[j])
        {
            y+=1;
        }
    }
    b[i]=y;
}

for(long i=0; i<1000; i++)
{
    fout << i-100 << "  " << b[i] << endl;
}

    return n;
}

int main()
{
    int N=5000, n=2000;
    r1(N,n);

    return 0;
}