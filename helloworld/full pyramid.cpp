#include <iostream>
using namespace std;

int main()
{
    for (;;)
    {
    int n, k;
    cin >> n;
    k = n;

    for(int i=0; i<n; i++)
    {
        for (int j=0; j<k-1; j++)
        {
            cout << " ";
        }

        k = k-1;

        for(int j=n-i; j<=n; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    }
}
