#include <iostream>
using namespace std;

int main()
{
    int var = 50;
    int *p;
    p = &var;

    cout << var <<  endl;

    cout << p << endl;

    cout << *p  << endl;

    return 0;
}
