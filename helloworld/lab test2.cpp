#include <iostream>
using namespace std;

void printMin(int arr[5]);
void printMax(int arr[5]);

int main()
{
    int x, y, z, a, b;
    cout << "Enter your 5 numbers: " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> a;
    cin >> b;
    int arr[5] = {x, y, z, a, b};
    printMin(arr);
    printMax(arr);

    return 0;
}

void printMin(int arr[5])
{
    int min = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    cout << "Minimum value is: " << min << endl;
}

void printMax(int arr[5])
{
    int max = arr[0];
    for(int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    cout << "Maximum value is: " << max << endl;

}
