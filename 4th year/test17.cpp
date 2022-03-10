#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

double dt = 0.25;

double f1(int N, double lambda)
{
	double x, m=0;
	
	for(int i=0; i<=N; i++)
	{
		x=(double)rand()/(double)RAND_MAX;
		if(x<=lambda*dt)
		{
			m+=1;
		}
	}
	
	return m;
}

int main()
{
	ofstream fout("test17.dat");
	int N1=100000, N2=50000, N3=50000;
	
	for(double t=0; t<=500; t+=dt)
	{
		fout << t << "  " << N1 << "  " << N2 << "  " << N3 << "  " << log(N1) << "  " <<  log(f1(N1, 0.08)) << endl;
		
		N1 -= f1(N1,0.08);
		N2 -= f1(N2, 0.08);
		N3 -= f1(N3, 0.05);
	}
	
	return 0;
}
