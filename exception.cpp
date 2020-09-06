#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

try
{
    int mohterAge = 29;
    int sonAge = 36;
    if (sonAge > motherAge)
    {
        throw 99;
    }
}

catch (int x)
{
    cout << "Wrong age values - Error" << endl;
}
