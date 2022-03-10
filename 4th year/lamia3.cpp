#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

void brownian(int N,int n)
{
int A[N];
for(int i=0;i<N;i++)
{
int x=0;
for(int j=0;j<n;j++)
{
double p=(double)rand()/(double)RAND_MAX;
      
if(p>0.5)
      
x=x+1;
      
else
      
x=x-1;
}
    
A[i]=x;
    
}
ofstream fout("brownian.dat");
for(int i=-n;i<=n;i++)
{
int count=0;
for(int j=0;j<N;j++)
{
if(A[j]==i)
count++;
}
fout<<i<<"   "<<count<<endl;
}
}

int main()
{
int n,N;
cout<<"enter the number of steps: "<<endl;
cin>>N;
cout<<"enter the number of time: "<<endl;
cin>>n;
srand(time(NULL));
brownian(N,n);
return 0;
}