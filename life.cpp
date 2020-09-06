#include <iostream>
using namespace std;

int main()
{
    int input;

    while (cin>>input)
    {
        if (input != 42)
        {
            cout << input << endl;
        }

        else
        {
            break;
        }
    }

    return 0;
}