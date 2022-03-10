
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("ass2.dat");
    double N=1000, n=N, nr=0, nl=N, x, y;
    srand(time(NULL));
    
    for(int t=0; t<=10000; t+=1)
    {
        x = (double)rand()/(double)RAND_MAX;
        y = n/N;
        if(x<=y)
        {
            n-=1;
        }
        else
        {
            n+=1;
        }

        fout << t << "  " << n  << "  "  << nl << endl; 

        nl += (1-(2*nl)/N);
    }

    return 0;
}
