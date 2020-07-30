#include <iostream>
#include <string>
using namespace std;

class Base
{
    string i;

public :
    void set_i(string a);
    string get_i();
};

void Base :: set_i(string a)
{
    i = a;
}

string Base :: get_i()
{
    return i;
}

class Child : public Base
{
    string j;

public:
    void set_j(string a);
    string get_str();
};

void Child :: set_j(string a)
{
    j = a;
}

string Child :: get_str()
{
    return get_i() + j;
}

int main()
{
    Child obj;

    obj.set_i("From Base class\n");
    obj.set_j("From Child class\n");

    cout << obj.get_str();
    return 0;
}
