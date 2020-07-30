#include <iostream>
using namespace std;

void setPointerValueToFive(int* x)
{
    cout << &x << "\n";
    *x = 5;
}

int main()
{
    int x = 3;
    setPointerValueToFive(&x);
    cout << "Thew value of x is " << x << endl;

    return 0;
}
