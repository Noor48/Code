#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>

using namespace std;
double f(double t, double x)
	{
		return 9*100*8.314* pow((t/428),3)* pow(x,4) *exp(x)/( pow((exp(x)-1),2));
	}
	
double p(double x,int n)
		{
			if(n==0)
			   return 1;
			 else if (n==1)
			    return x;
			  else 
			  return ((2*n-1)*x*p(x,n-1)-(n-1)*p(x,n-2))/n;
		}
		
double dp(double x, int n)
		{
			if(n==0)
			  return 0;
			  
			else
			  return n*(x*p(x,n)-p(x,n-1))/(x*x-1);			
		}

double gauss(double t)
{

	int n=20;
	double x0[n], x[n],w[n],xp[n],wp[n],c,h,s=0;
	double a= 0, b= 428/t;
	for(int i=0;i<n;i++)
		{
		   x0[i]= cos(M_PI* (i+1-0.25)/(n+0.5));
		   c=x0[i];
		   h=p(c,n)/dp(c,n);
		  
		   while(abs(h)>0.00001) 
		     {
		     	c=c-h;
		     	h= p(c,n)/dp(c,n);
		     }
		    
		    x[i]= c;
		    w[i]= 2/((1-c*c)* pow(dp(c,n),2));
		   
		}
		for(int i=0;i<n;i++)
		{
			xp[i]= 0.5*((b-a)*x[i]+ b+a);
			wp[i]= 0.5*(b-a)*w[i];	
		}
	
		for(int i=0;i<n;i++)
		{
			s+= wp[i]* f(t,xp[i]);
		}
		return s;
}

int main()
{
		ofstream file ("heat.dat");
		for(int a=5;a<=500;a++)
		  {
		  	file<< a<< "    "<< gauss(a)<<endl;
		  }
	return 0; 
}