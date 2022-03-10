#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

ofstream fout1("test141.dat");
ofstream fout2("test142.dat");
double dt=0.25;


double f1(int N, double lambda)
{
	int m=0;
	double x;
	for(int i=0; i<=N; i++)
	{
		x = (double)rand()/(double)RAND_MAX;
		if(x<=lambda*dt)
		{
			m++;
		}
	}
	
	return m;
}

int main()
{
	srand(time(NULL));
	int N1=10000, N2=5000, N3=5000;
	
	for(int t=0; t<=500; t++)
	{
		fout1 << t << "  " << N1 << "  " << N2 << " " << N3 << "  " << log(N1) << "  " << log(N2) << "  "  << log(N3) << "  " << log(f1(N1,0.08)) << endl;
		N1 -= f1(N1,0.08);
		N2 -= f1(N2,0.08);
		N3 -= f1(N3,0.05);
 	}
 	
 	return 0;
}
