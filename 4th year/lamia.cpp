#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

double f(double t,double N)
{
return N*exp(-0.08*t);
}

int main()
{
ofstream fout("assignment3.dat");
double N0,t0=0,lambda,a=0,b=0,x=0,y=0;
cout<<"Enter the particle number "<<endl;
cin>>N0;
cout<<"Enter decay contant: "<<endl;
cin>>lambda;

double t=t0,N=N0,dn=0,h=0.001,d[100000],n[100000],ta[100000];

for(int i=0;i<=100000;i++)
{

fout<<t<<"  "<<log(N)<<"  "<<log(abs(dn))<<"  "<<f(t,N0)<<endl;
n[i]=log(N);
d[i]=log(dn);
ta[i]=t;
dn=-N*lambda*h;
N-=N*lambda*h;
t+=h;

}

a=n[100];
b=n[1000];

x=ta[100];
y=ta[1000];

cout<<a<<"   "<<b<<endl;

double m=(b-a)/(y-x);

cout<<"slope of the graph is: "<<m<<endl;

return 0;
}