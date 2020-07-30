#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double h(double x, int n)
{
    if (n==0)
    {
        return 1;
    }

    else if (n==1)
    {
        return x;
    }

    else
    {
        return 2*x*h(x,n-1)-2*(n-1)*h(x,n-2);
    }
}

int main()
{
    ofstream fout ("h.dat");
    for(double x=-3; x<=3; x+=0.01)
    {
        fout << x << " " << h(x,0) << " " << h(x,1) << " " << h(x,2) << " " << h(x,3) << endl;
    }

    return 0;
}