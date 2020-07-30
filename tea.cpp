#include "Tea.h"
#include <iostream>
#include <string>
using namespace std;

Tea::Tea(int a, int b) :  regVar(a), constVar(b)
{
    cout << regVar << endl;
    cout << constVar << endl;
}

int main()
{
    Tea obj(42,33);

    return 0;
}