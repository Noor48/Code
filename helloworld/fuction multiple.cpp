#include <iostream>
using namespace std;

int substraction (int a, int b)
{
    int r;
    r = a - b;
    return r;
}

int main()
{
    int x = 3, y = 2, z;
    z = substraction(5, 3);
    cout << "The first result is: " << z << endl;
    cout << "The second result is: " << substraction(8, 9) << endl;
    cout << "The third result is: " << substraction(x, y) << endl;
    z = 4 + substraction(x, y);
    cout << "The forth result is: " << z << endl;

    return 0;
}
