#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a;
        cin >> b;

        if (a>b)
        {
            cout << 1 << "   " << a-b << endl;
        }

        else if (a<b)
        {
            cout << 2 << "  " << b-a << endl;
        }
    }

    return 0;
}
