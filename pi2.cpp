#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double pi(int n)
{
    int i=0, count=0;

    double x=0, y=0;
    srand(time(NULL));

    for(i=1; i<n; i++)
    {
        x = (double)rand()/(double)RAND_MAX;
        y = (double)rand()/(double)RAND_MAX;
        
        if (pow(pow(x,2)+pow(y,2),0.5)<=1)
        {
            count++;
        }
    }

    return 4*(double)count/(double)n;
}

int main()
{
    int i=0; 
    double val=0;

    for(i=10; i<=1000000; i*=10)
    {
        cout << pi(i) << endl;
    }

    return 0;
}