#include <iostream>
#include <string>
using namespace std;

class My
{
    public:
    My()
    {
        regvar = 0;
    }

    private:
    int regvar;

    friend void somefunc(My &obj);
};

void somefunc(My &obj)
{
    obj.regvar = 42;

    cout << obj.regvar << endl;
}

int main()
{
    My obj;
    somefunc(obj);

    return 0;
}