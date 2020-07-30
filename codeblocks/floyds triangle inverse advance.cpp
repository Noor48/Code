#include <iostream>
using namespace std;

int main()
{
    int i, j, n, k = 1;
    cout << "Enter your row number: " << endl;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
        {
            cout << k;
            k++;
        }

        cout << endl;
    }

    return 0;
}
