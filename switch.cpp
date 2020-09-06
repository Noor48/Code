#include <iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;

    switch(x)
    {
        case 1: cout << "Mon" << endl;
        break;
        case 2: cout << "Tue" << endl;
        break;
        case 3: cout << "Wed" << endl;
        break;
        
        default : cout << "Invalid" << endl;
    }

    return 0;
}