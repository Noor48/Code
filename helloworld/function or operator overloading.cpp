#include <iostream>
using namespace std;

class Polymorphism
{
public:
    Polymorphism(){}

        void sum(int n1, int n2)
        {
            cout << "Sum = " << n1 + n2 << endl;
        }

        void sum(int n1, int n2, int n3)
        {
            cout << "Sum = " << n1 + n2 + n3 << endl;
        }

        void sum(int n1, int n2, int n3, int n4)
        {
            cout << "Sum = " << n1 + n2 + n3 + n4 << endl;
        }

};

int main()
{
    Polymorphism obj;

    obj.sum(10, 15);

    obj.sum(10, 15, 20);

    obj.sum(10, 15, 20, 25);

    return 0;
}
