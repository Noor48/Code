#ifndef BOX
#define BOX

#include<cstdlib>
#include<cmath>
#include<random>
using namespace std;
double Box(double& x, double& y)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> r1(0, 1); 
    double p,q;

    p = r1(mt);
    q = r1(mt);

    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);
    
    return 0;
}

#endif