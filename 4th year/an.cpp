#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<time.h>
using namespace std;

FILE *t;

int main()
{

  int n, N;

  n = 100000; // number of walker
  N = 5000;    // number of steps
  
  t = fopen("rw.txt","w");

  double end[n];       

  int count[2*N+1];

  double prb[2*N+1];

  int m, seed;
  double x, sum=0.0;

  seed = time(NULL);
  srand(seed);

  for(int i=0; i<(2*N+1); i++)      

    {
      count[i] = 0;
      
      prb[i] = 0.0;
    }

 for(int i=0; i<n; i++)      
   {
     end[i] = 0;
     
    
   }

 //stepping

 for(int i=1; i<n; i++)
   {
     m = 0;  
     for(int j=1; j<=N; j++)
       {
  x = (double)rand() / (double)RAND_MAX;

  if(x<=0.5) m++;
  if(x>0.5) m--;
       }
     end[i] = m;
   }

 //setting degree

 for(int i=-N; i<=N; i++)
   {
     for(int j=0; j<n; j++)
       {
  if(i == end[j] ) {count[i+N]++; }
       }
   }

 //probability finding

 for(int i=0; i<(2*N+1); i++)
   {
     prb[i] = (double)count[i]/(double)n;
     if(count[i] != 0)  fprintf(t,"%d \t %d \t %lf \n",i-N,count[i], prb[i]); 
   }

//for(int i=0;i<=2*N;i++){
// sum+=prb[i];}
// cout<<sum<<endl;
 



 fclose(t);

  return 0;


}