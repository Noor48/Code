#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int l, m, n;
    cin >> l;
    cin >> m;
    cin >> n;
    int *array = new int [l, m, n];

    cout << "Enter your array: " << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> array[i][j][k];
            }
        }
    }

    cout << "Size of array: " << l << endl;
    cout << "You entered: ";
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << array[i][j][k];
            }
        }
    }

    delete[] array;
    return 0;
}
