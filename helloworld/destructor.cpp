#include <iostream>
using namespace std;

class Myclass
{
    int a;

public:
    Myclass();

    ~Myclass();

    void show();
};

Myclass::Myclass()
{
    cout << "In Constructor\n";
    a = 10;
}

Myclass::~Myclass()
{
    cout << "Destructing . ... . .  .\n";
}

void Myclass::show()
{
    cout << a << endl;
}

int main()
{
    Myclass obj;

    obj.show();

    return 0;
}

