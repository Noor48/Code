#include <iostream>
using namespace std;

void duplicate(int a,int b,int c)
{
    a = 2;
    b = 4;
    c = 6;
}

int main()
{
    int x = 1, y = 3, z = 5;
    duplicate(x, y, z);
    cout << "x = " << x << " y = " << y << " z = " << z << endl;
    return 0;
}
