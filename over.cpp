#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class My
{
    public:
    int var;
    My()
    {}

    My(int a)
    : var(a) {}

    My operator+(My obj)
    {
        My res;
        res.var = this->var+obj.var;
        return res;
    }
};

int main()
{
    My obj1(12), obj2(55);
    My res = obj1 + obj2;

    cout << res.var;

    return 0;
}