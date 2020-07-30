#include <iostream>
using namespace std;

class sum
{
public:

    int f(int m, int n)
    {
        int a[m][n];
        int b[m][n];
        int c[m][n] = {0};

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin >> b[i][j];
            }
        }

        for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << c[i][j] << " ";
        }

        cout << endl;
    }

        return 0;
    }
};

int main()
{
    int x, y;
    sum obj;
    cin >> x >> y;
    cout << obj.f(x, y);

    return 0;
}


