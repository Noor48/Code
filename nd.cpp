#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

void func(int N,double lambda)
{
	ofstream fout("nd.dat");
	double t=0;
	srand(time(NULL));
	while (N>0)
	{
		double delta_N=0;
			for (int i=1; i<=N; i++)
			{
				double r_i=(double) rand()/(double) RAND_MAX;
				if (r_i < lambda) delta_N+=1;
			}
		t+=1;
		N = N - delta_N;
		fout<<t<<"    "<<N<<" "<<-lambda*N<<" "<<log(N)<<"    "<<log(delta_N)<<endl;
	}
}

void func1(int N,double lambda)
{
	ofstream file("nd1.dat");
	double t=0;
	srand(time(NULL));
	while (N>0)
	{
	double delta_N=0;
		for (int i=1; i<=N; i++)
		{
			double r_i=(double) rand()/(double) RAND_MAX;
			if (r_i < lambda) delta_N+=1;
		}
		t+=1;
		N = N - delta_N;
		file<<t<<"  "<<N<<"  "<<-lambda*N<<"  "<<log(N)<<"  "<<log(delta_N)<<endl;
	}
}

int main ()
{
	func (2500,0.3);
	func1(240000,0.3);
	return 0;

}


