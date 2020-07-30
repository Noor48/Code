#include <iostream>
using namespace std;

double f(int a,int b,int c,int d,int e,int f,int g,int h)
{
    double r;

    r = (1 + 2*a)/3 + 4*(b + c)*(5 - d - e)/f - 6*(7/g + h);

    return r;
}

int main ()
{
    double z;
    z = f (10, 15, 20, 25, 30, 35, 40, 45);
    cout << "The result is: " << z;

    return 0;
}
