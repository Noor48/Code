#include <iostream>
using namespace std;

void setValueToFiveWithReference(int &x)
{
    x = 2;
}

int main()
{
    int x = 3;
    setValueToFiveWithReference(x);
    cout << "The value of x is " << x << "\n";

    return 0;
}
