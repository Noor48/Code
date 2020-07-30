#include <iostream>
using namespace std;

int main()
{
    int number = 88;
    int &refNumber = number;

    cout << number << endl;
    cout << refNumber << endl;

    refNumber = 99;
    cout << refNumber << endl;
    cout << number << endl;

    number = 55;
    cout << number << endl;
    cout << refNumber<< endl;

    return 0;
}
