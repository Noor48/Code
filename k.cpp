#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l = 5;
    int arr[l] = {20, 30, 50, 10, 40};

    for (int i=0; i<l-1; i++)
    {
        int j= i;

        for (int k=i; k<l; k++)
        {
            if(arr[k]<arr[j])

            {
                j = k;
            }
        }
        swap (arr[i], arr[j]);
    }

    for (int i=0; i<l; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
