#include <iostream>
using namespace std;

long factorial (long a)
{
    if (a > 1)
        return (a * factorial (a - 1));
    else
        return 1;
}

int main()
{
    long n;
    cout << "Enter number: ";
    cin >> n;

    cout << n << "! = " << factorial(n);

    return 0;
}
