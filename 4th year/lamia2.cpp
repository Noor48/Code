#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

double f(double t,double N,double nl)
{
return (1-2*nl/N);
}
void euler(double N)
{
ofstream file("diffusion_diff.dat");
double dt=0.1,nl=N;
for(double t=0;t<N*2;t+=dt)
{
file<<t<<"  "<<nl<<endl;

nl+=dt*f(t,N,nl);

}
}
void diffusion(int N)
{
int nl=N;
ofstream file("diffusion.dat");
for(int t=0;t<-N*2;N++)
{
double x=(double)rand()/(double)RAND_MAX;
   
if(x>(double)nl/(double)N)
   
nl=nl+1;
   
else
   
nl=nl-1;
   
file<<t<<"  "<<nl<<endl;
}
}
int main()
{
int N;
cout<<"enter the number"<<endl;
cin>>N;
euler(N);
diffusion((double)N);
return 0;
}