#include <iostream>
using namespace std;

int main()
{
    int i;
    double d;

    i = 3;
    d = i;
    cout << "d = " << d << endl;

    d = 5.5;
    i = d;
    cout << "i = " << i << endl;

    i = 6.6;
    cout << "i = " << i << endl;

    return 0;
}
