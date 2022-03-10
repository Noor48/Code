#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	ofstream fout("test18.dat");
	srand(time(NULL));
	int N=1000, n=100, r, a[N],c[2*n];
	double x,y,s,p[2*n];
	
	for(int i=0; i<=N; i+=1)
	{
		x=0;
		r = (rand()%n)+1;
		for(int j=0; j<=r; j+=1)
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
	
	for(int i=-n; i<=n; i+=1)
	{
		y=0;
		for(int j=0; j<=N; j+=1)
		{
			if(i==a[j])
			{
				y+=1;
			}
		}
		
		c[i+n]=y;
	}
	
	for(int i=0; i<2*n; i+=1)
	{
		p[i]=(double)c[i]/(double)N;
		fout << i-n << "  " << p[i] << endl;
	}
	
	return 0;
}
