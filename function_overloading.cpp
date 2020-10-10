#include <iostream>
using namespace std;

int sum (int a, int b)
{
    return a+b;
}

double sum (double a, double b)
{
    return a+b;
}

double sum (double a, double b, double c)
{
    return a+b+c;
}

int main()
{
    int a, b;
    double c, d,e;
    cout << "Enter number; ";
    cin >> a >> b >> c >> d;
    cout << sum(a,b) << endl;
    cout << sum(c,d) << endl;
    e = sum(a,b);
    cout << sum(a,b,e) << endl;
    
    return 0;
}