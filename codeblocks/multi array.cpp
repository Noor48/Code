#include <iostream>
using namespace std;

int main()
{
    int x [2][2] = {{1,2}, {2,3}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << x[i][j] << "\t ";
        }

        cout << endl;
    }

    return 0;
}
