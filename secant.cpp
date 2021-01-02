#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
    double f = pow(x,3) + x - 1;
    return f;
}

void secant(double x1, double x2, double e)
{
    double n=0, xm, x0, c;
    if(f(x1)*f(x2)!=0)
    {
        do
        {
            x0 = (x1*f(x2) - x2*f(x1)) / (f(x2) - f(x1));
            c = f(x1)*f(x0);
            x1 = x2;
            x2 = x0;
            n++;
            if(c==0)
            {
                break;
            }

            xm = (x1*f(x2)-x2*f(x1))/(f(x2) -f(x1)); 
        } while(abs(xm-x0)>= e);
        cout << "Root of the given equation= " << x0 << endl;
        cout << "No. of iteration= " << n << endl;
    }
}

int main()
{
    double x1=0.0, x2=1.0, e=0.0001;
    secant(x1,x2,e);

    return 0;
}