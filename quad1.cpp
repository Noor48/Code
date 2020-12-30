//A C++ Program To evaluate a Definite Integral by Gauss Quadrature

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//The given Function of Integration
double f(double x)
{
return x*x*x;
}
//Legendre's Polynomial P n (x)
double Pn(double x, int n){
if(n==0) return 1;
else if (n==1) return x;
else return (((2*n-1)*x*Pn(x,n-1))-((n-1)*Pn(x,n-2)))/n;
}
d
//Derivative of Legendre's Polynomial P n (x) i.e. dx (P n (x))
double d_Pn(double x,int n){
return (n/((x*x)-1))*(x*Pn(x,n)-Pn(x,n-1));
}
//The Gaussian Quadrature rule
void gauss_qua(double a,double b,int n){
//First find the solution of the n-th Legendre polynomial i.e. the n sample points x k ⁡(k = 1,2, . . . , n)
between the interval [-1,1]
if (n<=0)
cout<<"The number of sample points can not be negative or zero";
double x0[n],x[n],w[n],x_prime[n],w_prime[n],c,h;
int i;
for(i=0;i<n;i++){
x0[i]=cos((M_PI*((i+1)-0.25))/(n+0.5));/*initial guess of the k-th root of the n-th Legendre polynomial by Tricomi's approximation⁡x(n, k) =
cos(π ∗ (k − 0.25)/(n + 0.5)); where the values of k starts from 1 i.e. k=1,2,..,n. Thus to keep the
correct values of k , which is represented by i in the loop , we add 1 to i, otherwise the values of k will be
counted as k=0,1,....,n-1 which is not correct at all, but the array representation of the root needs to start i
from 0;*/
//Imprived root by Newton-Raphson method
c=x0[i];
h=Pn(c,n)/d_Pn(c,n);
while (abs(h)>=0.00000000001){
c=c-h;
h=Pn(c,n)/d_Pn(c,n);
}
cout<<c<<endl;
x[i]=c; // We store the root in an array
// Once the root is i.e. the sample point is found we calculate the weight
w[i]= (2/((1-c*c)*(d_Pn(c,n)*d_Pn(c,n))));
}
// Once the sample points (roots) and weights are calculated between [-1,1] (from the Legendre
polynomial) we need to rescale the values for our given interval [a,b]
for(i=0;i<n;i++){
x_prime[i]=0.5*(((b-a)*x[i])+(b+a));
w_prime[i]=0.5*(b-a)*w[i];
}
//Now everything is ready and we have to perform the last step of the algorith i.e. use Gaussian
Quadrature method defined in the equation
double result=0.0;
for(i=0;i<n;i++){
result+=(w_prime[i]*f(x_prime[i]));
}
// Now the desired result is shown below
cout<<"The value of integration is: "<<result<<endl;
/* If we use return type function then simply replace the cout line by return result
return result;*/
}
int main(){
double a,b;
int n;
cout<<"Enter the lower limit of integration: ";
cin>>a;
cout<<"Enter the upper limit of integration: ";
cin>>b;
cout<<"Enter the order n of the legendre polynomial: ";
cin>>n;
gauss_qua(a,b,n);
/* When the gauss_qua(a.b.n) is return type write the following
cout<<"The value of integration is: "<<gauss_qua(a,b,n)<<endl;*/
return 0;}