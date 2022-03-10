/*Consider on walking in a 1-dimentional linear path.The walkers are starting from the 0 point and  moving forward or backward by generating random numbers between 0 to 1 .If the number is greater then 0.5 the person move right or else in left  .Find the probability of landing at a given spot after a given number of step with a given walk and also draw the position vs probability graph.*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	ofstream fout("a1q2.dat");
	long long N=10000,n=1000,x,y,c[2*n+1],a[N];
	double long s,p[2*n+1],z=0;
	srand(time(NULL));
	for(int i=0;i<=N;i++)
	{
		x=0;
		for(int j=0;j<=n;j++)
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
		//cout << a[i] << endl;
	}

	for(int i=-n;i<=n;i++)
	{
		y=0;
		for(int j=0;j<=N;j++)
		{
			if(i==a[j])
			{
				y+=1;
			}
		}
		c[i+n]=y;
		//fout << i << "  " <<  c[i+n] << endl;
	}

	cout << c[2*n+1] << endl;
/*	
	for(int i=1; i<=2*n+1; i++)
	{
		z = (double)c[i]/(double)N;
		if(z!=0)
		{
			fout << i-n << "  " << z << endl;
		}
	}
*/
	for(int i=0;i<=2*n+1;i++)
	{
		z =(double)c[i]/(double)N;
		if(z!=0)
		{
			fout<<i-n<<" "<<z<<endl;
			//cout << c[2*n+1] << endl;
		}
	}
	return 0;
}	
