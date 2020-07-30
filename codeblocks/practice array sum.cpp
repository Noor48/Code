#include <iostream>
using namespace std;

void sum (int r, int c)
{
    int m1[r][c], m2[r][c], s[r][c];
    cout << "Enter 1st matrix: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m1[i][j];
        }
    }

    cout << "Enter 2nd matirx: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m2[i][j];
        }
    }

    cout << "Output: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            s[i][j] = m1[i][j] + m2[i][j];
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int row, col;

    cout << "Enter row number: ";
    cin >> row;

    cout << "Enter column number: ";
    cin >> col;

    sum (row, col);
    return 0;
}
