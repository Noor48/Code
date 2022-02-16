#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double t , double N)
{
	return -0.08*N;
}

double f2(double t, double N)
{
	return 0.1*exp(-0.1*t)-0.08*N;
}

void rk4(double t0, double N0)
{
	ofstream fout("test3.txt");
	double N=N0, t=t0, k1,k2,k3,k4, h=0.0001;
	for(t=t0; t<=100; t+=h)
	{
		fout << t << "  " << N << "  " << f1(t,N) << endl;

		k1=h*f2(t,N);
		k2=h*f2(t+h/2,N+k1/2);
		k3=h*f2(t+h/2,N+k2/2);
		k4=h*f2(t+h,N+k3);
		
		N += (k1 + 2*k2 + 2*k3 + k4)/6;
	}
}

int main()
{
	rk4(0,0);
	return 0;
}