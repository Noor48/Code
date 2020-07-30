#include <iostream>
using namespace std;

namespace a
{
    int i1 = 8;
    int i2 = 9;
}

namespace b
{
    int max(int n1, int n2)
    {
        return (n1 > n2) ? n1 : n2;
    }
}

int main()
{
    cout << a::i1 << endl;
    cout << b::max(a::i1, a::i2) << endl;
    return 0;
}
