#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f1(double t , double N)
{
       return  - 0.08*N;
  //  return N*exp(-0.08*t);
}

void p(double t0, double N0)
{
    ofstream fout("n.dat");
    ofstream file("n2.dat");
    double N=N0, k1,k2,k3,k4, h=0.0001;

    for(double t=t0; t<100; t+=0.001)
    {
        fout << t << "  " << log(N)  << "  "  <<  log(N0-N) << endl;
        file << t << "  " << N << "  " << N0-N <<  endl;
        
        k1 = h*f1(t,N);
        k2 = h*f1(t+h/2, N+k1/2);
        k2 = h*f1(t+h/2, N+k2/2);
        k4 = h*f1(t+h, N+k3);
        
        N += (k1 + 2*k2 + 2*k3 + k4)/6;
                

        //N += h*f1(t,N);
    }


}

int main()
{
    p(0,100000);
    return 0;
}