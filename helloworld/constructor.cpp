#include <iostream>
using namespace std;

class Myclass
{
    int a;

public:
    Myclass();

    void show();
};

Myclass::Myclass()
{
    cout << "In constructor\n";
    a = 10;
}

void Myclass::show()
{
    cout << a;
}

int main()
{
    Myclass o;

    o.show();

    return 0;
}
