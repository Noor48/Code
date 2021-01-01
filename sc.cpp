#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
double F1(double theta,double A)
{
	return 0.5*((A*cos(theta)+1)*sin(theta))/(pow(pow(A,2)+2*A*cos(theta)+1,2));
}
double S(double A)
{
	double a=0;
	double b=M_PI;
	int N=150;
	double h=(b-a)/N;
	double sum1=0;
	double sum2=0;
	double sum3=0;
	
	for(double i=1;i<N;i+=3)
	{
		sum1+=F1(a+i*h,A);
	}
	for(double j=2;j<N;j+=3)
	{
		sum2+=F1(a+j*h,A);
	}
	for(double k=3;k<N;k+=3)
	{
		sum3+=F1(a+k*h,A);
	
	}
	return (3*h/8)*(F1(a,A)+3*sum1+3*sum2+2*sum3+F1(b,A));
}
int main()
{
ofstream fout("sp1.dat");
for(double A=2;A<20;A+=0.01)
{
	fout<<A<<" "<<S(A)<<endl;
}
return 0;
}
