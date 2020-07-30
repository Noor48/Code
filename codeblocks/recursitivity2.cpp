#include <iostream>
using namespace std;

double long factorial (double long a)
{
    if (a > 1)
        return (a * factorial (a - 1));
        else
        return 1;
}

int main()
{
    double long n;
    cout << "Enter number: ";
    cin >> n;

    cout << n << "!: " << factorial(n) << endl;

    return 0;
}
