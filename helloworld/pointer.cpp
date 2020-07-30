#include <iostream>
using namespace std;

int main()
{
    int number = 30;
    int *p;
    p = &number;

    cout << "Address of the number: " << &number << endl;
    cout << "Address of p variable: " << p << endl;
    cout << "value of p variable is: " << *p << endl;

    return 0;
}
