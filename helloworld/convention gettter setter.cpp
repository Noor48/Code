#include <iostream>
using namespace std;

class Aaa
{
private:
    T i;

public:
    Aaa(T x)
    {
      i = x;
    }
};

T getI()const
{
    return i;
}

void setI(T x)
{
    i = x;
}

int main()
{
    Aaa obj;

    obj.show();

    return 0;
}
