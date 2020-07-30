#include <iostream>
#include <cmath>

using namespace std;

long double f (long double x)
{
    return sin(x);
}

 long double trap( long double a,long double b, int n)
{
    long double x, sum, del;
    del = (b-a)/n;
    sum = f(a);
    sum += f(b);
    x = a + del;
    for (int j=1; j<n; j++)
    {
        x += del;
        sum += 2.0*f(x);
    }

    return sum*0.5*del;
}

double simpson(double a , double b, int n)
{
    int i;
    long double d, I=0, J=0, A, K=0, E=0;
    d = (b-a)/n;
    for(int i=1; i<n; i++)
    {
        if ((i%2)!=0)
        {
            I = I + f(a + (i*d));
        }
    }

    for (i=2; i<n-1; i++)
    {
        if ((i%2)==0)
        {
            J = J + f(a + (i*d));
        }
    }

    A = (d/3)*(f(a) + (4*I) + (2*J) + f(b));

    return A;
}

double simpson3(double a, double b, int n)
{

    long double d, A3, I=0, J=0, K=0;
    d = (b-a)/n;
    for (int i=1; i<n; i++)
    {
        if (((i%2)!=0) && ((i%3)!=0))
        {
            I = I + f(a + (i*d));
        }
    }


    for (int i=1; i<n-1; i++)
    {
        if (((i%2)==0) && ((i%3)!=0))
        {
            J = J + f(a + (i*d));
        }
    }

    for (int i=2; i<n-2; i++)
    {
        if (((i%2)==0) && ((i%3)==0))
        {
            K = K + f(a + (i*d));
        }
    }

    A3 = (3*d/8)*(f(a) + 3*I + 3*J + 2*K + f(b));

    return A3;
}

int main()
{
    int i;
    long double a, b, d, n, I=0, J=0, K=0, E=0;
    cout << "Given f(x) = sin(x)" << endl;
    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;
    cout << "Enter number of intervals: " << endl;
    cin >> n;
    cout << "The value of integral under the entered limit is: " << endl;
    cout << trap(a, b, n) << endl;
    cout << simpson(a, b, n) << endl;
    cout << simpson3(a, b, n) << endl;
    return 0;
}
