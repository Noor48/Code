#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double l(double x, int n)
{
    if(n==0)
    {
        return 1;
    }

    else if (n==1)
    {
        return x;
    }

    else
    {
        return ((2*n-1)*x*l(x,n-1)-(n-1)*l(x,n-2))/n;
    }
}

int main()
{
    ofstream fout ("l.dat");
    for(double x=-1; x<=1; x+=0.001)
    {
        fout << x << " " << l(x,0) << " " << l(x,1) << " " << l(x,2) << " " << l(x,3) << endl;
    }

    return 0;
}