#ifndef BOX
#define BOX

#include<cstdlib>
double Box(double& x, double& y)
{
    double p,q;

    p = (double)rand()/(double)RAND_MAX;
    q = (double)rand()/(double)RAND_MAX;

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);
    
    return 0;
}

#endif