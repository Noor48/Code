#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double p(int n)
{
    int i=0, seed, count=0;
    double x=0, y=0;
    seed = time(NULL);
    srand(seed);
    for(i=1; i<=n; i++)
    {
        x = (double)rand()/(double) RAND_MAX;
        y = (double)rand()/(double) RAND_MAX;
        if(x*x+y*y<=1)
        {
            count++;
        }
    } 

    return 4*(double)count/(double)n;
}

int main()
{
    int i=0;
    double val;
    for(i=1000; i<=10000000; i*=10)
    {
        val = p(i);

        cout << val << endl;
    }

    return 0;
}