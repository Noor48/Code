#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double f1(double x)
{
    return (1+cos(x)*sin(abs(2*x)))/(1+abs(sin(x)));
}

double f2(double x)
{
    return 1/(1+pow(sin(x),2));
}

double m(double f(double x), double a, double b, double c, double d, int n)
{
    int i;
    double x, y, area;
    int s=0;
    for(i=1; i<=n; i++)
    {
        x=a+(b-a)*((double)rand()/(double) RAND_MAX);
        y=c+(d-c)*((double)rand()/(double) RAND_MAX);
        if(y<=f(x))
        {
            s++;
        }

        area=((double) s/(double) n)*(b-a)*(d-c);
    }

    return area;
}

int main()
{
    srand(time(NULL));
    cout << m(f1, -M_PI, M_PI,-0.3, 0.9, 1000) << endl;
    cout << m(f2, 0, M_PI/2,-0.3, 0.9, 1000) << endl;
    return 0;
}