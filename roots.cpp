#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;
    double r1, r2, d;

    cout << "Enter a, b, c : ";
    cin >> a >> b >> c;

    d = pow(b,2) - 4*a*c;

    if (d==0)
    {
        cout << "The roots are real and identical" << endl;
        r1 = (-b)/(2*a);
        cout << "The roots are: " << r1 << endl;
    }

    else if (d>0)
    {
        cout << "The roots are real and different " << endl;
        r1 = (-b+sqrt(d))/(2*a);
        r2 = (-b-sqrt(d))/(2*a);
        cout << "The roots art: " << r1 << "  " << r2 << endl;
    }

    else
    {
        cout << "The roots are imaginary " << endl;
        cout << (-b)/(2*a) << " + " << sqrt(-d) << "i" << endl;
        cout << (-b)/(2*a) << " - " << sqrt(-d) << "i" << endl;
    }

    return 0;
}