#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

<<<<<<< HEAD
try
{
    int mohterAge = 29;
    int sonAge = 36;
    if (sonAge > motherAge)
    {
        throw 99;
    }
}

catch (int x)
{
    cout << "Wrong age values - Error" << endl;
}
=======
int main()
{
    try
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
    
    }
    
    catch (int x) 
    {
        cout << "Divisiom by zero!";
    }
    
    return 0;
}
>>>>>>> 0f675aaea5439f839a7d9285ef78307e915b9ca9
