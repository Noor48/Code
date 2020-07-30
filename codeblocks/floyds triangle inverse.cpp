#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k = 1;
    cout << "Enter row:" << endl;
    cin >> n;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n-i; j++)
        {
            cout << k << " ";
            k++;
        }

        cout << endl;
    }
}
