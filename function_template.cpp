#include <iostream>
using namespace std;
template <class T>

T maxim(T x, T y)
{
    if (x>y)
    {
        return x;
    }

    else 
    {
        return y;
    }
}

int main()
{
    cout << maxim(10,5) << endl;
    cout <<  maxim(12.34f, 3456.34f) << endl;

    return 0;
}