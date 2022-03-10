#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;

int main()
{
	ofstream fout("test15.dat");
	srand(time(NULL));
	int N=100000, n=1000, a[N], c[2*n],x, y;
	double p[2*n], r,s;
	
	for(int i=0; i<=N; i++)
	{
		x=0;
		r = (rand()%n)+1;
		for(int j=0; j<=r; j++)
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
	
	for(int i=-n; i<=n; i++)
	{
		y=0;
		for(int j=0; j<=N; j++)
		{
			if(i == a[j])
			{
				y+=1;
			}
		}
		c[i+n] = y;
	}
	
	for(int i=0; i<=2*n; i++)
	{
		p[i] = (double)c[i]/(double)N;
		fout << i-n << "  " << p[i] << endl;
	}
	
	return 0;
}
