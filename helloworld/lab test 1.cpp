#include <iostream>
using namespace std;

double f (double cel)
{
    double r;
    r = (cel * 9.0)/5.0 + 32;
    return r;
}

int main()
{
    double z;
    double x;
    cout << "Enter your number: " << endl;
    cin >> x;
    z = f(x);
    cout << "Farenheit: " << z << endl;

    return 0;
}
