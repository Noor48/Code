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
    cout << "In Constructor\n";
    a = 10;
}

void Myclass::show()
{
    cout << a;
}

int main()
{
    Myclass obj;

    obj.show();

    return 0;
}
