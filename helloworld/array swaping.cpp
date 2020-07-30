#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l = 5;
    int array[l] = {30, 50, 20, 10, 40};

    for (int i = 0; i < l - 1; i++)
    {
        int j = i;

        for (int k = i + 1; k < l;  k++)
        {
            if (array[k]<array[j])
                 j = k;
        }

        swap (array[i], array[j]);
    }

    for (int i = 0; i < l; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
