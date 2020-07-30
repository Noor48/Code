#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fact (int n)
{
    if (n<=1)
    {
        return 1;
    }

    else 
    {
        return n*fact(n-1);
    }
}

double bernoulli(int n)
{
    double sum=0;
    for(int p=1; p<=20; p++)
    {
        sum += pow(p,-2*n);
    }

    return (pow(-1, n-1)*2*fact(2*n)*sum)/(pow(2*M_PI, 2*n));
}

double mytan(double x, int n)
{
    double sum=0;

    for(int i=0; i<=n; i++)
    {
        sum += (pow(-1,i-1)*pow(2,2*i)*(pow(2,2*i)-1)*bernoulli(i)*pow(x,2*i-1))/fact(2*i);
    }

    return sum;
}

int main()
{
    ofstream fout ("ber.dat");
    for(double x=-M_PI/3; x<=M_PI/3; x+=0.0001)
    {
        fout << x << " " << mytan(x,20) << endl;
    }

    return 0;
}