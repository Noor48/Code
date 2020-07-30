#include <iostream>
using namespace std;

int main()
{
    int x[2][3][2] =
    {
        {{2, 3}, {3, 4}, {4, 5}},
        {{5, 6}, {6, 7}, {7, 8}}
    };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << x[i][j][k] << "\t";
            }

        }

    }

    return 0;
}
