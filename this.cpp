#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class My 
{
    public:

    My (int a) 
    : var(a)
    {}

    void printinfo()
    {
        cout << var << endl;
        cout << this->var << endl;
        cout << (*this).var << endl;
    }

    private:
    int var;
};

int main()
{
    My obj(42);
    obj.printinfo();

    return 0;
}