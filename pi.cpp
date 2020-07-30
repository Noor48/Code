#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double pi(int n)
{
    int seed,c=0;
    double x=0, y=0;
    seed = time(NULL);
    srand(seed);
    for(int i=0; i<=n; i++)
    {
        x = (double)rand()/(double) RAND_MAX;
        y = (double)rand()/(double) RAND_MAX;
        if(sqrt(x*x + y*y)<=1)
        {
            c++;
        }
    }

    return 4*(double)c/(double)n;
}

int main()
{
    double val=0;
    for(int i=1000; i<=10000000; i*=10)
    {
        cout << pi(i) << endl;
    }

    return 0;
}