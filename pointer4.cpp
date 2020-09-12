#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter number: ";
    cin >>size;
    int *p = new int [size];

    cout << "Enter new size: ";
    cin >> size;
    p = new int[size];

    return 0;
}