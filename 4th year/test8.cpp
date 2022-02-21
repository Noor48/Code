#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("test8.dat");
    int t = 100000, w=1000,x;
    double p;

    int *wc = new int [w+1];
    int *wc2 = new int [w+1];
    for(int i=1; i<=w; i++)
    {
        wc[w] = wc2[w] = 0;
    }

    srand(time(NULL));
    for(int i=1; i<=t; i++)
    {
        x=0;
        for(int j=1; j<=w; j++)
        {
            double s = (double)rand()/(double)RAND_MAX;
            if(s>0.5)
            {
                x++;
            }

            else
            {
                x--;
            }
        }
        wc[i] = x;
        wc2[i] = x*x;
    }

    for (int i=1; i<=t; i++)
    {
        double x1 = wc[i]/(double)t;
        double x2 = wc2[i]/(double)t;
        double v = x2-x1*x1;
        fout << i << "  " << v << endl;
    }
}