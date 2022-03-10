#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("test13.dat");
    srand(time(NULL));

    double Nz=100000,  dn, dt=0.25, lambda=0.08, x;
    
    for(double t=0; t<=100; t+=dt)
    {   
        dn=0;
        for(int i=0; i<=N; i++)
        {
            x = (double)rand()/(double)RAND_MAX;
            if(x <=0.08*dt)
            {
                dn+=1;
            }
        }

        N = N-dn;
        fout << t << "  " <<  N << "  " <<  log(N) << "  " << log(abs(dn)) << endl;
    }

    return 0;
}