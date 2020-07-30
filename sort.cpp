#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l = 5;
    int array[l] = {30, 50, 20, 10, 40};

    sort (array, array + l);

    for (int i = 0; i < l; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
