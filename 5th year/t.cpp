#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("t.dat");
    srand(time(NULL));

    double x=0, dx, x0, s, s0,m,sum=0, sum2=0;
    int k, n=10E5, c=2,i=0;
    
    #pragma omp parallel for
    for(k=1; k<=n; k++)
    {
        x0=x;
        s0=pow(x,2)*0.5;

        dx = (double)rand()/(double)RAND_MAX;
        dx = (dx-0.5)*2*c;
        x += dx;

        m = (double)rand()/(double)RAND_MAX;
        s = pow(x,2)*0.5;


        if(exp(s0-s)>m)
        {
            i+=1;
        }

        else
        {
            x=x0;
        }

        sum += x;
        sum2 += pow(x,2);
        fout << x  << "  " << sum/k <<"  " << k << "  " << sum2/k << endl;
    }
    return 0;
}