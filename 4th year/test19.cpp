#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	ofstream fout("test19.dat");
	srand(time(NULL));
	
	double N=1000, n=N, nl=N, x,y,h=1;
	for(int t=0; t<=10000; t+=h)
	{
		x = (double)rand()/(double)RAND_MAX;
		y = n/N;
		if(x<=y)
		{
			n-=1;
		}
		
		else
		{
			n+=1;
		}
		
		fout << t << "  " << n << "  " << nl << endl;
		nl += h*(1-(2*nl)/N);
	}
	
	return 0;
}
