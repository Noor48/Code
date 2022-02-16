/*
Consider on walking in a 1-dimentional linear path.The walkers are starting from the 0 point and  moving forward or backward by generating random numbers between 0 to 1 .If the number is greater then 0.5 the person move right or else in left  .Find the probability of landing at a given spot after a given number of step with a given walk and also draw the position vs probability graph. 
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<ctime>

using namespace std;


int main()
{
ofstream fout("walk.dat");

  int n=100000, N=5000,m,count[2*N+1];
  double a[n], p[2*N+1], x, sum=0;

  srand(time(NULL));

  for(int i=0; i<(2*N+1); i++)      

    {
      count[i] = 0;
      
      p[i] = 0.0;
    }

 for(int i=0; i<n; i++)      
   {
     a[i] = 0;
         
   }


 for(int i=1; i<n; i++)
   {
     m = 0;  
     for(int j=1; j<=N; j++)
       {
  x = (double)rand() / (double)RAND_MAX;

  if(x>0.5) m++;
  if(x<=0.5) m--;
       }
     a[i] = m;
   }

 for(int i=-N; i<=N; i++)
   {
     for(int j=0; j<n; j++)
       {
  if(i == a[j] ) {count[i+N]++; }
       }
   }

 for(int i=0; i<(2*N+1); i++)
   {
     p[i] = (double)count[i]/(double)n;
     if(count[i] != 0)  fout<<i-N<<" "<<p[i]<<endl;
   }


}