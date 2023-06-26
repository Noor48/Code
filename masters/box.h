#ifndef BOX
#define BOX


#include<cstdlib>
#include<cmath>
#include<random>
using namespace std;


//Gaussian Random Number Generator with Box Muller Algorithm
double Box(double& x, double& y)
{
    //uniform random numbers between 0 and 1
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> r1(0, 1); 
    double p,q;

    p = r1(mt);
    q = r1(mt);


    //Gaussina random numbers with weights proportional to e^{-x^2/2} and e^{-y^2/2}
    x = sqrt(-2*log(p))*sin(2*M_PI*q);
    y = sqrt(-2*log(p))*cos(2*M_PI*q);

    
    return 0;
}

#endif
