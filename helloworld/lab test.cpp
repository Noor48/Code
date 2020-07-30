#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a = 5;
    int arr[a] = {10, 5, 20, 45, 40};

    for (int i = 0; i < a - 1; i++)
    {
        int j = i;

        for (int k = i + 1; k < a; k++)
        {
            if (arr[k] > arr[j])
                j = k;
        }
        swap (arr[i], arr[j]);
    }

    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
