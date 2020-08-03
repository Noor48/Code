#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

template <class T>
T sum (T a, T b)
{
    return a+b;
}

int main()
{
    int x=7, y=15;
    cout << sum(x,y) << endl;

    return 0;
}