#include <iostream>
using namespace std;

void setValueToFive(int x)
{
    cout << &x <<"\n";
    x = 5;
}

int main()
{
    int x = 3;
    setValueToFive(x);
    cout << "The value of x is " << x << " , setValueToFive() did not modify x. \n";

    return 0;
}
