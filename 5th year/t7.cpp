#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<complex>
using namespace std;

int main()
{
    srand(time(NULL));
    double p,q,a,b;

    p = (double)rand()/(double)RAND_MAX;
    q = (double)rand()/(double)RAND_MAX;
    
    a = sqrt(-2*log(p))*sin(2*M_PI*q);
    b = sqrt(-2*log(p))*cos(2*M_PI*q);
    
}