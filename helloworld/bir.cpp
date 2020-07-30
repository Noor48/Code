#include "bir.h"
#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    Person(string n, Birthday b)
    : name(n), bd(b)
    {}

    void printinfo()
    {
        cout << name << endl;
        bd.printdate();
    }

    private:
    string name;
    Birthday bd;
};

int main()
{
    Birthday bd(2,21,1985);
    Person p("David", bd);
    p.printinfo();

    return 0;
}