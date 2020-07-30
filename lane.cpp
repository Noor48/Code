#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
//double s=1;
double f(double x,double y,double v,double s)
{
return v;
}

double g(double x,double y,double v,double s)
{

return -(2/x)*v-pow(y,s);

}

double r(double v,double y)
{
ofstream fout("lem.dat");
double h=0.01;
//double k1,k2,k3,k4,l1,l2,l3,l4;
for(double xo=1;xo<=20;xo+=h)
{
fout<<xo<<"  ";
for(double s=0;s<=4;s++)
{
double vo=v,yo=y;
for(double x=1;x<=xo;x+=h)
{
vo+=h*g(x,yo,vo,s);
yo+=h*f(x,yo,vo,s);
}
fout<<yo<<"  ";
}
fout<<endl;
}
}
int main()
{
r(0,1);
}