#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    double num1;
    cout << "Enter ther first number: ";
    cin >> num1;

    double num2;
    cout << "Enter the second number: ";
    cin >> num2;

    if (num2 == 0)
    {
        throw 0;
    }

    cout << "Result: " << num1/num2;

    return 0;
}