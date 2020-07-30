#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1( double v, double x,double y,double s)
{
	
	return -(2*v)/x-pow(y,s);
}

double f2 ( double v, double x, double y,double s)
{
	return v;
}

void rk4( double v0,double y0,double s)
{
	ofstream fout ("rk4.dat");
	double  v=v0, y=y0,k1, k2, k3, k4, l1, l2, l3, l4,h=0.1;
	for(double x=0.1; x<=20; x+=h)
	{
		fout << x << " " << y << " " << endl;
		 
		k1 = h*f1(v,x,y,s);
		l1 = h*f2(v,x,y,s);
		k2 = h*f1(v+k1/2, x+h/2,y+l1/2, s);
		l2 = h*f2(v+k1/2, x+h/2,y+l1/2,s);
		k3 = h*f1(v+k2/2, x+h/2,y+l2/2,s);
		l3 = h*f2(v+k2/2, x+h/2,y+l2,s);
		k4 = h*f1(v+k3, x+h,y+l3,s);
		l4 = h*f2(v+k3, x+h,y+l3,s);
		
		v += (k1 + 2*k2 + 2*k3 + k4)/6;
		
		y += (l1 + 2*l2 + 2*l3 + l4)/6;
		
	}
	
	
}

int main()
{	
	rk4(0,1,2);
}
