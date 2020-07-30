#include <iostream>
using namespace std;

void printArray (int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = {5, 15, 25, 35, 45};

    printArray(arr1);
    printArray(arr2);

    return 0;
}
