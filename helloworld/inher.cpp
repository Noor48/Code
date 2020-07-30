#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Mother
{
    public:
    
    Mother()
    {
        cout << "Mother ctor" << endl;
    }

    ~Mother()
    {
        cout << "Mother dtor" << endl;
    }
};

int main()
{
    Mother m;

    return 0;
}