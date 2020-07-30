#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(1);

    cout << (double)5 << endl;
    cout << (int)5.5 << endl;

    double aDouble = 5.6;
    int anInt = (int)aDouble;

    cout << double(5) << endl;
    cout << int(5.5) << endl;
    cout << int(aDouble) << endl;

    return 0;
}
