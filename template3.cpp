#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class Myclass
{
    public:
    Myclass (T x)
    {
        cout << x << " - not a char" << endl;
    }
};

template <>
class Myclass<char>
{
    public:
    Myclass (char x) 
    {
        cout << x <<" is a char!" << endl;
    }
};

int main()
{
    Myclass <int> obj1(42);
    Myclass <double> obj2(5.47);
    Myclass <char> obj3('s');
    
    return 0;
}