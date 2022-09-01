#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<complex>
using namespace std;

double random(double& a, double& b)
{

    a = (double)rand()/(double)RAND_MAX;
    b = (double)rand()/(double)RAND_MAX;
    
    return 0;
}

double Box(double& a, double& b)
{
    double x,y;
    x = random(a);
    y = random(b);

    a = sqrt(-2*log(x)*sin(2*M_I*y));
    b = sqrt(-2*log(x)*cos(2*M_I*y));

    return 0;   
}


int main()
{
    srand(time(NULL));
    complex <double> A[5][5] = {0};
    complex <double> B[5][5] = {0};
    
    double p,q,x,y;
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            random(p,q);
            A[i][j] = complex(p,q);
        }
    }

    for(int i=; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            Box(x,y);

        }
    }
}