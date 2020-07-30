#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i=2; i<=b; i++)
    {
        if (a*i!=b)
        {
            cout << i << " ";
        }

    }
}
